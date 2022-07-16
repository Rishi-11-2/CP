#include <stdio.h>
#include <stdlib.h>
int main()
{
    int c = 0;
    int nw = 1, nc = 0;
    FILE *f;
    if ((f = fopen("D:\\program.txt", "r")) == NULL)
    {
        printf("ERROR IN OPENING FILE");
        exit(1);
    }
    char a[100];
    for (int i = 0; i < 100; i++)
    {
        a[i] = '@';
    }
    while (c != EOF)
    {
        c = getc(f);
        if (c != ' ')
        {
            a[nc++] = c;
        }
        else
        {
            nw++;
            a[nc++] = ' ';
        }
    }
    printf("THE NUMBER OF CHARACTERS=%d AND THE NUMBER OF WORDS=%d", nc, nw);
    printf("\nTHE FILE CONTENTS ARE->\n");
    for (int i = 0; i < 100; i++)
    {
        if (a[i] != '@')
        {
            printf("%c ", a[i]);
        }
    }
}