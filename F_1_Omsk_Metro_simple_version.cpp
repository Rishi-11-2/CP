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
    map<int, int> m;
    m[1] = 1;
    int mn = 2;
    vector<int> adj[3 * n + 1];
    vector<string> res;
    vector<pair<pair<int, int>, int>> q;
    map<pair<int, int>, int> mp;
    map<pair<int, int>, pair<int, int>> np;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(mn);
            adj[mn].push_back(u);
            m[mn] = v;
            mn++;
        }
        else if (c == '?')
        {
            int u, v, w;
            cin >> u >> v >> w;
            q.push_back({{u, v}, w});
        }
    }
    vector<int> vis(3 * n + 1, 0);
    function<void(int, int, int, int, int)> dfs = [&](int i, int maxSum, int minSum, int gMin, int gMax) -> void
    {
        vis[i] = 1;
        int x1 = gMin;
        int y1 = gMax;
        for (int v : adj[i])
        {
            if (vis[v] == 1)
                continue;
            // cout << v << endl;
            int a = 0;
            int b = 0;
            a = min(min(m[v], minSum), minSum + m[v]);
            b = max(max(m[v], maxSum), maxSum + m[v]);
            gMin = min(gMin, a);
            gMax = max(gMax, b);
            // cout << gMin << " " << gMax << endl;
            np[{1, v}] = {gMax, gMin};
            dfs(v, max(m[v], maxSum + m[v]), min(m[v], minSum + m[v]), gMin, gMax);
            gMin = x1;
            gMax = y1;
        }
    };
    int minm = 1;
    int maxm = 1;
    int sum = 0;
    np[{1, 1}] = {1, 1};
    dfs(1, 1, 1, 1, 1);
    for (auto it : q)
    {
        auto i = it.first;
        int w = it.second;
        if ((w <= np[i].first && w >= np[i].second) || w == 0)
            res.push_back("YES");
        else
            res.push_back("NO");
    }
    for (auto it : res)
        cout << it << endl;
}