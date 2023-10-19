#include <stdio.h>
#include <stdlib.h>
int count = 10;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node Node;

void create(Node *root)
{
    printf("DO YOU WANT A LEFT CHILD FOR THIS NODE?  -1 for NO->");
    int val;
    scanf("%d", &val);
    if (val != -1)
    {
        Node *y = (Node *)malloc(sizeof(Node *));
        y->data = val;
        y->left = NULL;
        y->right = NULL;
        root->left = y;
    }
    printf("DO YOU WANT A RIGHT CHILD FOR THIS NODE?  -1 for NO->");
    int val2;
    scanf("%d", &val2);
    if (val2 != -1)
    {

        Node *y = (Node *)malloc(sizeof(Node *));
        y->data = val2;
        y->left = NULL;
        y->right = NULL;
        root->right = y;
    }

    if (root->left != NULL)
        create(root->left);
    if (root->right != NULL)
        create(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main()
{
    Node *y = (Node *)malloc(sizeof(Node *));
    y->data = 10;
    y->left = NULL;
    y->right = NULL;
    Node *root = y;
    create(root);
    inorder(root);
}