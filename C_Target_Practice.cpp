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
    char c[10][10];
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 'X')
            {
                int k1 = 0;
                for (int k = 0; k <= 5; k++)
                {
                    if (i == (k - 1) || j == (k - 1) || j == (10 - k) || i == (10 - k))
                    {
                        k1 = k;
                        break;
                    }
                }
                // cout << i << " " << j << " " << k1 << endl;
                sum += k1;
            }
        }
    }
    cout << sum << endl;
}