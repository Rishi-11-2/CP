#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin >> n;
    int arr[n + 3];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n; i < n + 3; i++)
        arr[i] = 0;
    vector<vector<int>> dp(n + 3, vector<int>(2, 0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][1] = min(dp[i + 1][0], dp[i + 2][0]);
        dp[i][0] = min(arr[i] + dp[i + 1][1], dp[i + 2][1] + arr[i] + arr[i + 1]);
    }
    cout << dp[0][0] << endl;
}