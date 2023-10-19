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
    int n, k, c;
    cin >> n >> k >> c;
    vector<int> adj[n + 1];
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(n + 1, 0);
    vector<int> res;
    vector<int> vt;
    int flag = 0;
    function<void(int, int)> dfs = [&](int u, int i) -> void
    {
        vis[u] = 1;
        int x = 0;
        for (int v : adj[u])
        {
            if (!vis[v])
            {
                x = 1;
                dfs(v, i + 1);
            }
        }
        if (x == 0)
        {
            res.push_back(i);
        }
    };
    vis[1] = 1;
    for (int v : adj[1])
    {
        // flag = 1;
        dfs(v, 1);
        sort(all(res));
        vt.push_back(res[res.size() - 1]);
        res.clear();
    }
    int y = 0;
    sort(all(vt));
    reverse(all(vt));
    // for (auto it : vt)
    //     cout << it << " ";
    // cout << endl;
    if (k > c && vt.size() > 1)
    {
        int m = vt.size();
        int maxm = 0;
        for (int i = 1; i < m; i++)
        {
            maxm = max(maxm, vt[0] * k + vt[i] * k - c * vt[i]);
        }
        y = maxm;
    }
    else
    {
        // cout << v[0] << endl;
        y = vt[0] * k;
    }
    cout << y << endl;
}