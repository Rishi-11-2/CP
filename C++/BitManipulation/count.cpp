#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int t = 0;
    while (n)
    {
        n = (n & (n - 1));
        t++;
    }
    cout << t;
}