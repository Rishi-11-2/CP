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
void bfs(int i, vector<int> &dist, int n, vector<set<int>> adj)
{
    queue<int> q;
    q.push(i);
    vector<int> vis(n + 1, 0);
    vis[i] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] > dist[u] + 1)
                dist[v] = dist[u] + 1;
            if (vis[v] == 0)
            {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[k];
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i - 1];
    }
    vector<set<int>> adj(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[y].insert(x);
        adj[x].insert(y);
    }
    vector<int> dist1(n + 1, INT_MAX);
    vector<int> dist2(n + 1, INT_MAX);

    bfs(1, dist1, n, adj);
    bfs(n, dist2, n, adj);

    vector<pair<int, int>> data;
    for (int i = 0; i < k; i++)
    {
        data.push_back({dist1[a[i]] - dist2[a[i]], a[i]});
    }
    sort(all(data));
    for(int i=0;i<k;i++)
    {
        
    }
}