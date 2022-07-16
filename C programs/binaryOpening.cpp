#include <stdio.h>
#include <stdlib.h>
struct threeNum
{
    int n1, n2, n3;
};
int main()
{
    int n;
    struct threeNum num;
    FILE *fptr;
    if ((fptr = fopen("D:\\program.bin", "rb")) == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    for (n = 1; n < 5; ++n)
    {
        fread(&num, sizeof(struct threeNum), 1, fptr);
        printf("n1:%d\tn2: %d\t n3:%d", num.n1, num.n2, num.n3);
        printf("\n");
    }
    fclose(fptr);
    return 0;
}