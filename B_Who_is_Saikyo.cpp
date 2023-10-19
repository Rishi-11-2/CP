#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();

class Disjoint
{
public:
    vector<int> rank, parent, size;

    Disjoint(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node);
    void unionBySize(int u, int v);
};
int Disjoint::findUPar(int node)
{
    if (node == parent[node])
    {
        return node;
    }
    return parent[node] = findUPar(parent[node]);
}

void Disjoint ::unionBySize(int u, int v)
{
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
        return;
    if (size[ulp_v] <= size[ulp_u])
    {
        size[ulp_u] += size[ulp_v];
        parent[ulp_v] = ulp_u;
    }
    else
    {
        size[ulp_v] += size[ulp_u];
        parent[ulp_u] = ulp_v;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
void solve()
{
    int n, m;
    cin >> n >> m;
    set<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
    }
    for (int i = 1; i <= n; i++)
    {
        queue<int> q;
        vector<int> vis(n + 1, 0);
        vis[i] = 1;
        q.push(i);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (vis[v] == 0)
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        int count = 0;
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] == 1)
                count++;
        }
        if (count == n)
        {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}