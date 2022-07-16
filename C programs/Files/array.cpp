#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num[10];
    for (int i = 0; i < 10; i++)
    {
        num[i] = 0;
    }
    FILE *fptr;
    if ((fptr = fopen("D:\\program.txt", "r")) == NULL)
    {
        printf("ERROR OPENING FILES");
        exit(1);
    }
    int c = 0;
    int t = 0;
    while (c != EOF)
    {
        fscanf(fptr, "%d", &num[t++]);
        c = getc(fptr);
    }
    fclose(fptr);
    for (int i = 0; i < 10; i++)
    {
        if (num[i])
            printf("%d\n", num[i]);
    }
    printf("%d\n", t);
}