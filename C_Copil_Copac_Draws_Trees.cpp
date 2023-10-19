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
    vector<int> dp(n + 1, 0);
    vector<int> id(n + 1, 0);
    vector<vector<pair<int, int>>> edges(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[x].push_back({y, i});
        edges[y].push_back({x, i});
    }
    dp[1] = 1;

    function<void(int)> dfs = [&](int u) -> void
    {
        for (auto it : edges[u])
        {
            if (dp[it.first] == 0)
            {
                dp[it.first] = dp[u] + (it.second <= id[u]);
                id[it.first] = it.second;
                dfs(it.first);
            }
        }
    };
    dfs(1);
    int maxm = 0;
    for (auto it : dp)
        maxm = max(maxm, it);
    cout << maxm << endl;
}