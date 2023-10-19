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
bool myCmp(vector<long long> &a, vector<long long> &b)
{
    return a[0] > b[0];
}
void solve()
{
    long long n;
    cin >> n;
    vector<vector<long long>> v;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = i + 1; j <= n; j++)
        {
            long long x;
            cin >> x;
            v.push_back({x, i, j});
        }
    }
    sort(all(v), myCmp);
    long long m = v.size();
    long long z = (1 << 18) * 1LL;
    vector<vector<long long>> dp(m + 1, vector<long long>(z + 1, -1LL));
    // vector<long long> dp(z + 1, -1);
    function<long long(long long, long long)> f = [&](long long i, long long mask) -> long long
    {
        if (i >= m || mask == z)
            return 0;

        if (dp[i][mask] != -1)
            return dp[i][mask];
        long long x = v[i][1];
        long long y = v[i][2];
        long long ans = 0LL;
        if (((mask & (1 << x)) == 0) && ((mask & (1 << y)) == 0))
        {
            // cout << x << " " << y << " " << v[i][0] << endl;
            long long newMask = mask;
            // cout << newMask << endl;
            newMask = (1 << x) | newMask;
            newMask = (1 << y) | newMask;
            ans = max(ans, v[i][0] + f(i + 1, newMask));
        }
        ans = max(ans, f(i + 1, mask));
        return dp[i][mask] = ans;
    };
    long long x = f(0, 0);
    cout << x << endl;
}