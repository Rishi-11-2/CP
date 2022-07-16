#include <bits/stdc++.h>
using namespace std;

bool isZero(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
}