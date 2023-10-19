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
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> v;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
    }
    queue<int> q;
    vector<int> parent(n + 1, 0);
    vector<int> dis(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        dis[v[i]] = 0;
        parent[v[i]] = 0;
        q.push((v[i]));
    }
    int ans = 0;
    vector<int> res(n + 1, 0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto it : adj[u])
        {
            if (parent[it.first] == u)
                continue;
            if (dis[it.first] <= d)
            {
                res[it.second] = 1;
            }
            else if (dis[u] < d)
            {
                dis[it.first] = dis[u] + 1;
                parent[it.first] = u;
                q.push(it.first);
            }
        }
    }
    for (int i = 1; i <= n - 1; i++)
    {
        ans += res[i];
    }
    cout << ans << endl;
    for (auto it : res)
        cout << it << " ";
    cout << endl;
}