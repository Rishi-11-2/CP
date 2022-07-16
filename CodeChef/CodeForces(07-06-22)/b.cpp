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
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int d = a[0] - b[0];
        int flag = 0;
        for (int i = 1; i < n; i++)
        {
            int p = a[i] - b[i];
            d = max(p, d);
        }
        for (int i = 0; i < n; i++)
        {
            if (d > (a[i] - b[i]))
            {
                if (b[i] != 0)
                {
                    flag = 1;
                }
            }
        }
        if (flag == 1 or d < 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}