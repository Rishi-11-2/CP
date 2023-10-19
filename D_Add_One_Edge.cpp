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
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    vector<int> adj1[n1 + 1];
    vector<int> adj2[n2 + 1];
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > n1)
        {
            adj2[a - n1].push_back(b - n1);
            adj2[b - n1].push_back(a - n1);
        }
        else
        {
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }
    }
    queue<int> q;
    q.push(1);
    vector<int> vis(n1 + 1, 0);
    vector<int> dis(n1 + 1, INT_MAX);
    dis[1] = 0;
    vis[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj1[u])
        {
            if (vis[v] == 0)
            {
                vis[v] = 1;
                if (dis[v] > dis[u] + 1)
                    dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    int res1 = 0;
    for (auto i : dis)
    {
        if (i != INT_MAX)
            res1 = max(res1, i);
    }
    q.push(n2);
    vector<int> vis2(n2 + 1, 0);
    vector<int> dis2(n2 + 1, INT_MAX);
    dis2[n2] = 0;
    vis2[n2] = 1;
    int c = 0;
    cout << endl;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj2[u])
        {
            if (vis2[v] == 0)
            {
                vis2[v] = 1;
                if (dis2[v] > dis2[u] + 1)
                    dis2[v] = dis2[u] + 1;
                q.push(v);
            }
        }
    }
    int res2 = 0;
    for (auto i : dis2)
    {
        if (i != INT_MAX)
            res2 = max(res2, i);
    }
    cout << res1 + res2 + 1 << endl;
}