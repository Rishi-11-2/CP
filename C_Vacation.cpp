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
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, y, z});
    }
    int dp[n + 1][3];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = v[i - 1][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = v[i - 1][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = v[i - 1][2] + max(dp[i - 1][1], dp[i - 1][0]);
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
}