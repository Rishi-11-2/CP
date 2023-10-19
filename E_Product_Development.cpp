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
    long long n, k, p;
    cin >> n >> k >> p;
    vector<vector<long long>> v(n, vector<long long>(k + 1, 0));
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j <= k; j++)
            cin >> v[i][j];
    }
    long long req = (1 << (k + 1));
    // cout << req << endl;
    map<pair<long long, >, long long> dp;
    function<long long(long long, long long, vector<long long>)> f = [&](long long i, long long mask, vector<long long> vis) -> long long
    {
        // cout << i << " " << mask << endl;
        int flag = 0;
        for (int i = 1; i <= k; i++)
        {
            if (vis[i] < p)
                flag = 1;
        }
        if (flag == 0)
        {
            return 0;
        }
        if (i == n)
        {
            return (long long)(1e11);
        }
        if (dp.find({i, vis}) != dp.end())
            return dp[{i, vis}];
        long long res = f(i + 1, mask, vis);
        long long s = 0;
        for (long long j = 1; j <= k; j++)
        {
            if (vis[j] == p)
                continue;
            if (vis[j] < p)
            {
                vis[j] = min(p, vis[j] + v[i][j]);
            }
        }
        long long newMask = mask;
        for (long long j = 1; j <= k; j++)
        {
            if (vis[j] == p)
                newMask = newMask | (1 << j);
        }
        res = min(res, v[i][0] + f(i + 1, newMask, vis));
        return dp[{i, vis}] = res;
    };
    vector<long long> vis(k + 1, 0);
    long long x = f(0, 1, vis);
    if (x == (long long)(1e11))
        cout << -1 << endl;
    else
        cout << x << endl;
}