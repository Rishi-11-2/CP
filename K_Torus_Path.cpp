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
    long long n;
    cin >> n;
    vector<vector<long long>> arr(n + 1, vector<long long>(n + 1, 0));
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
    vector<vector<long long>> vis(n + 1, vector<long long>(n + 1, 0));
    function<long long(long long, long long)> f = [&](long long i, long long j) -> long long
    {
        if (i == n - 1 && j == n - 1)
            return arr[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        if (vis[i][j] == 1)
            return 0;
        vis[i][j] = 1;
        long long x1 = i;
        long long y1 = (j + 1) % n;
        long long x2 = (i + 1) % n;
        long long y2 = j;
        long long s1 = f(x1, y1);
        long long s2 = f(x2, y2);
        long long s = max(s1, s2) + arr[i][j];
        return dp[i][j] = s;
    };
    cout << f(0, 0) << endl;
}