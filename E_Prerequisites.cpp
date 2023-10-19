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
    vector<int> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    vector<int> vis(n + 1, 0);
    vector<int> res;
    function<void(int)> dfs = [&](int i) -> void
    {
        vis[i] = 1;
        for (int v : adj[i])
        {
            if (vis[v] == 0)
                dfs(v);
        }
        res.push_back(i);
    };
    dfs(1);
    for (auto it : res)
    {
        if (it == 1)
            continue;
        cout << it << " ";
    }
    cout << endl;
}