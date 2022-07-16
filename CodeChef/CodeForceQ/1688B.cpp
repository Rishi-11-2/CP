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
        {
            cin >> a[i];
        }
        int od = 0, ev = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2)
                od++;
            else
                ev++;
        }
        if (od)
        {
            cout << ev << '\n';
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                int tt = 0;
                while (a[i] % 2 == 0)
                {
                    a[i] /= 2;
                    tt++;
                }
                ans = min(ans, tt);
            }
            cout << ans + ev - 1 << '\n';
        }
    }
}