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
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> first;
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (first.find(arr[i - 1]) == first.end())
        {
            dp[i] = dp[i - 1];
            first[arr[i - 1]] = i - 1;
        }
        else
        {
            dp[i] = max(dp[i - 1], dp[first[arr[i - 1]]] + ((i - 1) - first[arr[i - 1]] + 1));
            if ((dp[i - 1] - (i - 1)) >= (dp[first[arr[i - 1]]] - first[arr[i - 1]]))
            {
                first[arr[i - 1]] = i - 1;
            }
        }
    }
    // // cout << endl;
    // for (auto it : dp)
    //     cout << it << " ";
    // cout << endl;
    cout << dp[n] << endl;
}