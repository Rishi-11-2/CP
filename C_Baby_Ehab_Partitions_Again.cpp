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
    int n;
    cin >> n;
    int arr[n];
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }
    if (s % 2)
    {
        cout << 0 << endl;
        return;
    }
    int target = s / 2;
    long long dp[n + 1][target + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    // knapsack DP
    //  This is because we are trying to reach the target . if some of elemetns equal target then the
    // sum of the rest of the elements will be equal to sum -target which will be equal to target .
    // Therefore we uses knapsack dp
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= target; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << s << endl;
    if (dp[n][target] == 1)
    {
        cout << 1 << endl;
        for (int i = 0; i < n; i++)
        {
            int x = (s - arr[i]);
            if (x % 2)
            {
                cout << i + 1 << endl;
                return;
            }
            x = x / 2;
            if (dp[n - 1][x] == 0)
            {
                cout << i + 1 << endl;
                return;
            }
        }
    }
    else
        cout << 0 << endl;
}