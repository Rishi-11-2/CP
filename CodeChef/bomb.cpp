#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        int y = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] == x)
            {
                y = i;
            }
            if (a[i] > x)
                break;
        }
        cout << y << endl;
    }
}