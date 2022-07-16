#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t = 1;
    int c = 0;
    FILE *fptr;
    if ((fptr = fopen("D:\\program.txt", "r")) == NULL)
    {
        printf("ERROR OPENING FILE");
        exit(1);
    }
    while (c != EOF)
    {
        c = getc(fptr);
        if (c == '\n')
            t++;
    }
    printf("THE NUMBER OF LINES IN FILE IS ->%d", t);
}