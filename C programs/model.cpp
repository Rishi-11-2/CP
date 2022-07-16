#include <stdio.h>
bool isPrime(long long int a)
{
    for (long long int i = 2; i <= a / 2; i++)
    {
        if (i % 2 == 0)
            return false;
    }
    return true;
}
int main()
{
    long double a = 1;
    long double b = 2;
    long double t = 0;
    printf("%lld  %lld ", a, b);
    for (int i = 3; i <= 25; i++)
    {
        t = b;
        b = b * a;
        a = t;
        if (b != 0)
            printf("%lld  ", b);
    }
    printf("\n");
    printf("THE PRIME NUMBERS ARE ->");
    a = 1;
    b = 2;
    t = 0;
    for (int i = 1; i <= 25; i++)
    {
        if (isPrime(a) == true && a != 0)
        {
            printf("%lld  ", a);
        }

        t = b;
        b = b * a;
        a = t;
    }
}