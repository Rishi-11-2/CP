#include <stdio.h>
int fib(int n)
{
    return n < 2 ? n : fib(n - 1) + fib(n - 2);
}

int main()
{
    int a = 0;
    int b = 1;
    int n;
    int t = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int m = 0; m <= 100; m++)
        {
            printf(" ");
        }
        for (int j = 1; j < ((n - i + 1) * 2) - 1; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= ((i * 2) - 1); k++)
        {
            printf("%d ", fib(t++));
        }
        printf("\n");
    }
}