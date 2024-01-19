#include<stdio.h>
int main()
{
        int x=1;
        char *y=(char*)&x;
        if(*y==1)
        printf("Little Endian");
        else
        printf("Small Endian");
}
