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
        for (int i = 0; i < n; i++)
            a[i] = 0;
        int b[2 * n];

        bool cond = false;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> b[i];
        }
        int t = 0;
        for (int i = 1; i < 2 * n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[j] == 0 || a[j] == -b[i])
                {
                    a[j] = b[i];
                    break;
                }
                else
                    t++;
            }
        }
        if (t > n)
            cond = false;
        if (cond)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}