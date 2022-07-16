#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;

    cin >> t;

    while (t-- > 0)
    {
        int x, y, k, n;
        cin >> x >> y >> k >> n;
        int a[n];
        int b[n];
        bool cond = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= x - y)
            {
                if (b[i] <= k)
                {
                    cond = true;
                }
            }
        }
        if (cond)
            cout << "LUCKY CHEF";
        else
            cout << "UNLUCKY CHEF";
        cond = false;
    }
}