#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    TOKEN_NUMBER,
    TOKEN_VARIABLE,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_END,
    TOKEN_INVALID
} TokenType;

typedef struct {
    TokenType type;
    double value;
    char variable;
} Token;

Token getNextToken(const char **expr) {
    Token token = {TOKEN_INVALID, 0, '\0'};
    while (*expr && isspace(*expr)) (*expr)++;
    if (**expr == '\0') {
        token.type = TOKEN_END;
    } else if (isdigit(**expr) || **expr == '.') {
        token.type = TOKEN_NUMBER;
        token.value = strtod(*expr, (char **)expr);
    } else if (isalpha(**expr)) {
        token.type = TOKEN_VARIABLE;
        token.variable = **expr;
        (*expr)++;
    } else {
        switch (**expr) {
            case '+': token.type = TOKEN_PLUS; break;
            case '-': token.type = TOKEN_MINUS; break;
            case '*': token.type = TOKEN_MULTIPLY; break;
            case '/': token.type = TOKEN_DIVIDE; break;
            case '(': token.type = TOKEN_LPAREN; break;
            case ')': token.type = TOKEN_RPAREN; break;
            default: token.type = TOKEN_INVALID; break;
        }
        (*expr)++;
    }
    return token;
}

typedef struct ASTNode {
    TokenType type;
    double value;
    char variable;
    struct ASTNode *left;
    struct ASTNode *right;
} ASTNode;

ASTNode *parseExpression(const char **expr);
ASTNode *parseTerm(const char **expr);
ASTNode *parseFactor(const char **expr);

ASTNode *parseExpression(const char **expr) {
    ASTNode *left = parseTerm(expr);
    while (1) {
        Token token = getNextToken(expr);
        if (token.type == TOKEN_PLUS || token.type == TOKEN_MINUS) {
            ASTNode *right = parseTerm(expr);
            ASTNode *root = (ASTNode *)malloc(sizeof(ASTNode));
            root->type = token.type;
            root->left = left;
            root->right = right;
            left = root;
        } else {
            (*expr)--;
            break;
        }
    }
    return left;
}

ASTNode *parseTerm(const char **expr) {
    ASTNode *left = parseFactor(expr);
    while (1) {
        Token token = getNextToken(expr);
        if (token.type == TOKEN_MULTIPLY || token.type == TOKEN_DIVIDE) {
            ASTNode *right = parseFactor(expr);
            ASTNode *root = (ASTNode *)malloc(sizeof(ASTNode));
            root->type = token.type;
            root->left = left;
            root->right = right;
            left = root;
        } else {
            (*expr)--;
            break;
        }
    }
    return left;
}

ASTNode *parseFactor(const char **expr) {
    Token token = getNextToken(expr);
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    switch (token.type) {
        case TOKEN_NUMBER:
            node->type = TOKEN_NUMBER;
            node->value = token.value;
            break;
        case TOKEN_VARIABLE:
            node->type = TOKEN_VARIABLE;
            node->variable = token.variable;
            break;
        case TOKEN_LPAREN:
            node = parseExpression(expr);
            if (getNextToken(expr).type != TOKEN_RPAREN) {
                printf("Error: Missing closing parenthesis\n");
                exit(EXIT_FAILURE);
            }
            break;
        default:
            printf("Error: Invalid expression\n");
            exit(EXIT_FAILURE);
    }
    return node;
}

double evaluate(ASTNode *root) {
    if (root->type == TOKEN_NUMBER) {
        return root->value;
    } else if (root->type == TOKEN_VARIABLE) {
        printf("Error: Variables not supported\n");
        exit(EXIT_FAILURE);
    } else {
        double left = evaluate(root->left);
        double right = evaluate(root->right);
        switch (root->type) {
            case TOKEN_PLUS: return left + right;
            case TOKEN_MINUS: return left - right;
            case TOKEN_MULTIPLY: return left * right;
            case TOKEN_DIVIDE:
                if (right == 0) {
                    printf("Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                return left / right;
            default:
                printf("Error: Invalid expression\n");
                exit(EXIT_FAILURE);
        }
    }
}

void printAST(ASTNode *root, int level) {
    if (root != NULL) {
        for (int i = 0; i < level; i++) {
            printf("|   ");
        }
        printf("|-- ");
        if (root->type == TOKEN_NUMBER) {
            printf("Value: %.2f\n", root->value);
        } else if (root->type == TOKEN_VARIABLE) {
            printf("Variable: %c\n", root->variable);
        } else {
            switch (root->type) {
                case TOKEN_PLUS: printf("Operator: +\n"); break;
                case TOKEN_MINUS: printf("Operator: -\n"); break;
                case TOKEN_MULTIPLY: printf("Operator: *\n"); break;
                case TOKEN_DIVIDE: printf("Operator: /\n"); break;
                default: printf("Unknown operator\n"); break;
            }
            printAST(root->left, level + 1);
            printAST(root->right, level + 1);
        }
    }
}

int main() {
    const char *expr = "(3 + 4) * (5 - 2)";
    ASTNode *root = parseExpression(&expr);
    printf("Abstract Syntax Tree:\n");
    printAST(root, 0);
    double result = evaluate(root);
    printf("Result: %.2f\n", result);

    return 0;
}