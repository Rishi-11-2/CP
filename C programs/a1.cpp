#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    FILE *fptr;
    if ((fptr = fopen("D:\\program.txt", "r")) == NULL)
    {
        printf("ERROR OPENING FILES");
        exit(1);
    }
    for (int i = 0; i < 3; i++)
    {
        fscanf(fptr, "%d", &num);
        printf("THE VALUE OF NUM =%d\n", num);
    }
    fclose(fptr);
    return 0;
}