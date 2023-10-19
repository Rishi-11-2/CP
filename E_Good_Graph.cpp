#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Disjoint
{
    vector<int> rank, parent, size;

public:
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
    void unionByRank(int u, int v);
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
void Disjoint::unionByRank(int u, int v)
{
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
        return;
    if (rank[ulp_u] < rank[ulp_v])
    {
        parent[ulp_u] = ulp_v;
    }
    else if (rank[ulp_v] < rank[ulp_v])
    {
        parent[ulp_v] = ulp_u;
    }
    else
    {
        parent[ulp_u] = ulp_v;
        rank[ulp_v]++;
    }
}
void Disjoint ::unionBySize(int u, int v)
{
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
        return;
    if (size[ulp_v] < size[ulp_u])
    {
        size[ulp_u] += size[ulp_v];
        parent[ulp_v] = ulp_u;
    }
    else
    {
        size[ulp_v] += size[ulp_u];
        parent[ulp_u] = ulp_v;
    }
};
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
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    Disjoint d(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        d.unionBySize(x, y);
    }
    vector<int> x(n + 1, 0);
    int t;
    cin >> t;
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= t; i++)
    {
        int u, v;
        cin >> u >> v;
        int ulp_u = d.findUPar(u);
        int ulp_v = d.findUPar(v);
        mp[{ulp_u, ulp_v}] = 1;
    }
    // Disjoint d2 = d;
    int k;
    cin >> k;
    vector<string> res;
    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        // d2.unionBySize(a, b);
        int ulp_a = d.findUPar(a);
        int ulp_b = d.findUPar(b);
        if (mp[{ulp_a, ulp_b}] == 1 || mp[{ulp_b, ulp_a}] == 1)
            res.push_back("No");
        else
            res.push_back("Yes");
    }
    for (auto it : res)
        cout << it << endl;
}