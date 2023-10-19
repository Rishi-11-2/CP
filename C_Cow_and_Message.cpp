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
    string s;
    cin >> s;
    long long n = s.length();
    long long dp[26][26];
    vector<long long> v(26, 0);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        v[s[i] - 'a']++;
    for (int i = 0; i < n; i++)
    {
        int ind = s[i] - 'a';
        v[ind]--;
        for (int j = 0; j < 26; j++)
        {
            dp[ind][j] += v[j];
        }
    }
    long long res = 0;
    for (int i = 0; i < n; i++)
        v[s[i] - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            // cout << dp[i][j] << " ";
            res = max(res, dp[i][j]);
        }
        res = max(res, v[i]);
        // cout << endl;
    }
    cout << res << endl;
}