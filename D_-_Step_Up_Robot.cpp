#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define all(v) (v).begin(), (v).end()
#define int long long int
#define lld long double
void solve();
int32_t main()
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
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    map<int, int> m1;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        m1[x] = 1;
    }
    int k;
    cin >> k;
    vector<int> dp(k + 1, -1);
    for (int i = 0; i < n; i++)
    {
        if (m1[arr[i]] != 1 && arr[i] <= k)
            dp[arr[i]] = 1;
    }
    for (int j1 = 0; j1 <= k; j1++)
    {
        if (m1[j1] != 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (j1 - arr[i] >= 0)
                {
                    if (dp[j1 - arr[i]] != -1)
                    {
                        dp[j1] = 1;
                    }
                }
            }
        }
    }
    // for (int i = 0; i <= k; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    cout << endl;
    if (dp[k] == -1)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}