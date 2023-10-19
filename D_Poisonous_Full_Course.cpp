#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
void solve()
{
    long long n;
    cin >> n;
    vector<vector<long long>> v;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        vector<long long> a;
        a.push_back(x);
        a.push_back(y);
        v.push_back(a);
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    long long prev = 0;
    long long prev2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i - 1][0] == 0)
        {
            dp[i][1] = dp[i - 1][1];
            dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][0] + v[i - 1][1]), dp[i - 1][1] + v[i - 1][1]);
        }
        else if (v[i - 1][0] == 1)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + v[i - 1][1]);
        }
    }
    cout << max(dp[n][1], dp[n][0]) << endl;
}