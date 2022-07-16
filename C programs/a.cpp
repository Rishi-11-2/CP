#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    FILE *fptr;
    fptr = fopen("D:\\program.txt", "w");
    if (fptr == NULL)
    {
        printf("ERROR OPENING FILES");
        exit(1);
    }
    printf("ENTER NUM:");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num);
        fprintf(fptr, "%d", num);
    }

    fclose(fptr);
    return 0;
}