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
    double d;
    cin >> n >> d;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            double x = abs(v[i].first - v[j].first) * 1.0;
            double y = abs(v[i].second - v[j].second) * 1.0;
            double dis = sqrt((x * x) + (y * y));
            // cout << dis << " " << d << endl;
            if (dis <= d)
            {
                // cout << i << " " << j << endl;
                adj[i].push_back(j);
            }
        }
        // cout << endl;
    }
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            // cout << v << " " << u << endl;
            if (vis[v] == 0)
            {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}