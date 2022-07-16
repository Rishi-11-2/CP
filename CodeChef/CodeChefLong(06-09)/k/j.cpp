#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int x = 0;
        int y = 0;

        for (int i = 1; i <= q; i++)
        {
            bool flag = true;
            y = 0;
            int h;
            cin >> h;
            int p = 1;
            while (x < h)
            {
                x += a[n - 1 - y];
                p++;
                y++;
                if (y == (n))
                {
                    flag = false;
                    break;
                }
            }
            if (flag == false)
            {
                cout << -1 << endl;
            }
            cout << (y + 1) << endl;
        }
    }
}