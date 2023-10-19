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
    long long x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    long long n = s.length();
    // cout << s << endl;
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = z;
    bool flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'a')
        {
            dp[i][0] = (x + dp[i - 1][0]);
            dp[i][1] = min(dp[i - 1][0] + x + z, dp[i - 1][1] + y);
        }
        else if (s[i - 1] == 'A')
        {
            dp[i][0] = min(dp[i - 1][0] + y, dp[i - 1][1] + z + x);
            dp[i][1] = (x + dp[i - 1][1]);
        }
    }
    // for (auto &it : dp)
    //     cout << it[0] << " " << it[1] << endl;
    // cout << endl;
    cout << min(dp[n][0], dp[n][1]) << endl;
}