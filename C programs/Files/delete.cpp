#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *f;
    FILE *f2;

    if ((f = fopen("D:\\program.txt", "r")) == NULL)
    {
        printf("ERROR OPENING FILE");
        exit(1);
    }
    if ((f2 = fopen("D:\\program1.txt", "w")) == NULL)
    {
        printf("ERROR OPENING FILE");
        exit(1);
    }
    int ln;
    printf("ENTER THE LINE NUMBER ->");
    scanf("%d", &ln);
    int t = 1;
    int c = 0;
    while (c != EOF)
    {
        c = getc(f);
        if (c == '\n')
            t++;
        if (t != ln)
        {
            fprintf(f2, "%c", c);
        }
    }
    fclose(f);
    fclose(f2);
    c = 0;

    if ((f = fopen("D:\\program.txt", "wb")) == NULL)
    {
        printf("ERROR OPENING FILE");
        exit(1);
    }
    if ((f2 = fopen("D:\\program1.txt", "r")) == NULL)
    {
        printf("ERROR OPENING FILE");
        exit(1);
    }
    while (c != EOF)
    {
        c = getc(f2);
        fprintf(f, "%c", c);
    }
    fclose(f);
    fclose(f2);
}