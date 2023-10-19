
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define all(v) (v).begin(), (v).end()
#define int long long int
#define lld long double
vector<int> adj[200005];
int cc = 1;
vector<vector<int>> cycles;
void dfs(int node, vector<bool> &vis)
{
    // Mark the current node as visited
    vis[node] = true;

    // Traverse the adjacency list
    // of the current node
    for (auto x : adj[node])
    {

        // For every unvisited node
        if (!vis[x])
        {
            cc++;

            // Recursive DFS Call
            dfs(x, vis);
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

#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n + 1, false);
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cc = 1;
            dfs(i, vis);
            c++;
        }
    }

    cout << m - n + c << endl;
}