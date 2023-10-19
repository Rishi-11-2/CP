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
int dfs(int i, vector<long long> adj[], vector<long long> &vis, vector<long long> &leaf, int n)
{
    vis[i] = 1;
    int x = 0;
    int flag = 0;
    for (int v : adj[i])
    {
        if (vis[v] == 1)
            continue;
        x += dfs(v, adj, vis, leaf, n);
        flag = 1;
    }
    if (flag == 0)
        x = 1;
    leaf[i] = x;
    return x;
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<long long> vis(n + 1, 0);
    vector<long long> leaf(n + 1, 0);
    long long c = dfs(1, adj, vis, leaf, n);
    long long q;
    cin >> q;
    vector<long long> res;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        res.push_back(leaf[x] * leaf[y] * 1LL);
    }
    for (auto it : res)
        cout << it << endl;
}