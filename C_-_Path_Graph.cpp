#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define all(v) (v).begin(), (v).end()
#define int long long int
#define lld long double
void BFS(vector<int> adj[], int s, vector<bool> &visited)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto it : adj[x])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }
}
void solve();
int32_t main()
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
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int c = 0;
    int d = 0;
    for (int i = 1; i <= n; i++)
    {
        auto it = adj[i];
        if (it.size() == 1)
            c++;
        if (it.size() == 2)
            d++;
    }
    vector<bool> visited(n + 1, false);
    int f = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            BFS(adj, i, visited);
            f++;
        }
    }
    if (f > 1)
    {
        cout << "No" << endl;
    }
    else if (c != 2)
    {
        cout << "No" << endl;
    }
    else if (d != n - 2)
    {
        cout << "No" << endl;
    }
    else if (c == 2 && d == (n - 2))
        cout << "Yes" << endl;
}