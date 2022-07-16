#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n == 0)
        cout << "NOT A POWER OF TRUE";
    else
    {
        if (!((n & (n - 1))))
            cout << "POWER OF TWO";
        else
            cout << "NOT A POWER OF TWO";
    }
}