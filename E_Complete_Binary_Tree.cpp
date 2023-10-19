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
    int n, x, k;
    cin >> n >> x >> k;
    map<pair<int, int>, int> mp;
    int count = 0;
    function<int(int, int)> f = [&](int i, int d) -> int
    {
        if (mp.find({i, d}) != mp.end())
        {
            return mp[{i, d}];
        }
        if (d == k)
        {
            int x1 = 0;
            if (i <= n && i >= 1 && i != x)
            {
                count++;
                cout << i << endl;
                x1 = 1;
            }
            return mp[{i, d}] = x;
        }
        int x = f(i * 2, d + 1);
        int y = f(i * 2 + 1, d + 1);
        int z = f(i / 2, d + 1);
        int res = x + y + z;
        return mp[{i, d}] = res;
    };
    // cout << endl;
    int y = f(x, 0);
    cout << count << endl;
}