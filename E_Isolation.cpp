#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
class DSU
{
    vector<int> parent;
    vector<int> size;
    DSU(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUlp(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findUlp(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);
        if (size[ulp_u] > size[ulp_v])
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
};
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
    set<int> s;
    set<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x;
        if (x == 1)
        {
            cin >> y >> z;
            adj[y].insert(z);
            adj[z].insert(y);
            s.insert(y);
            s.insert(z);
        }
        else
        {
            int v;
            cin >> v;
            s.erase(v);
            for (auto it : adj[v])
            {
                adj[it].erase(v);
                if (adj[it].size() == 0)
                    s.erase(it);
            }
            adj[v].erase(all(adj[v]));
        }
        cout << n - s.size() << endl;
    }
}