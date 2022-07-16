#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int n = 0;
    int j = x;
    if (x == INT_MIN)
    {
        return 0;
    }
    x = (abs)(x);
    while (x > 0)
    {
        n = (n * 10) + (x % 10);
        if (n > INT_MAX)
        {
            return 0;
        }
        x /= 10;
    }
    if (j < 0)
    {
        return -n;
    }
    else
    {
        return n;
    }
}