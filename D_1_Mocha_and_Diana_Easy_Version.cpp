#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
class Disjoint
{
public:
    vector<int> parent, size;
    Disjoint(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUlp(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUlp(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
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
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> adj1[n + 1];
    vector<int> adj2[n + 1];
    Disjoint d1(n);
    Disjoint d2(n);
    for (int i = 1; i <= m1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj1[x].push_back(y);
        adj1[y].push_back(x);
        d1.unionBySize(x, y);
    }
    for (int i = 1; i <= m2; i++)
    {
        int x, y;
        cin >> x >> y;
        adj2[x].push_back(y);
        adj2[y].push_back(x);
        d2.unionBySize(x, y);
    }
    // cout << "Ho" << endl;
    vector<vector<int>> res;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            int ulp_i = d1.findUlp(i);
            int ulp_j = d1.findUlp(j);

            int ullp_i = d2.findUlp(i);
            int ullp_j = d2.findUlp(j);
            if (ulp_i != ulp_j && ullp_i != ullp_j)
            {
                res.push_back({i, j});
                d1.unionBySize(i, j);
                d2.unionBySize(i, j);
            }
        }
    }
    cout << res.size() << endl;
    for (auto it : res)
        cout << it[0] << " " << it[1] << endl;
}