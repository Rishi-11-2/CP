#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int l, r;
    cin >> l >> r;
    if (l == r)
    {
        for (int i = 2; i <= min(100000, l); i++)
        {
            if ((l - i) % i == 0 && (l - i) != 0)
            {

                cout << i << " " << l - i << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
    else
    {
        int a = 2;
        for (int i = l; i <= r; i++)
        {
            if ((i - a) % 2 == 0)
            {
                if ((i - a) > 1)
                {
                    cout << 2 << " " << i - a << endl;
                    return;
                }
            }
        }
        cout << -1 << endl;
    }
}