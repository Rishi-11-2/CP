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
    long long n, m, k;
    cin >> n >> m >> k;
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    priority_queue<pair<long long, pair<long long, long long>>> pq;
    vector<long long> vis(n + 1, 0);
    map<long long, long long> xdis;
    vector<long long> dis(n + 1, INT_MAX);
    map<long long, long long> mp;
    vector<long long> v;

    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        pq.push({y, {x, x}});
        dis[x] = 0;
        mp[x] = y;
        vis[x] = 1;
    }
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int u = it.second.first;
        int parent = it.second.second;
        int d = it.first;
        // cout << u << endl;
        for (int v : adj[u])
        {

            if (d + 1 < dis[v])
            {
                xdis[v] = parent;
                dis[v] = d + 1;
                vis[v] = 1;
                pq.push({d + 1, {v, parent}});
            }
        }
    }
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == 0)
        {
            res.push_back(i);
            continue;
        }
        if (dis[i] <= mp[xdis[i]])
            res.push_back(i);
    }
    cout << (int)(res.size()) << endl;
    for (auto it : res)
        cout << it << " ";
    cout << endl;
}