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

    solve();
}
void solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    int count = 0;
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!flag && i % m == 0)
        {
            flag = 1;
            count++;
        }
        else if (flag && (i - m) % p == 0)
        {
            // cout << i << endl;
            count++;
        }
    }
    cout << count << endl;
}