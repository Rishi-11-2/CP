#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int m = 0;
        int y = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m = max(a[i], m);
        }
        cout << m << y;
    }
}