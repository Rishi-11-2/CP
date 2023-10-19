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
void solve();
int dfs(vector<int> adj[], vector<int> &vis, int s, int &nV)
{
    vis[s] = 1;
    int nE = adj[s].size();
    for (int u : adj[s])
    {
        if (vis[u] == 0)
        {
            nV++;
            nE += dfs(adj, vis, u, nV);
        }
    }
    return nE;
}
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
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            int nV = 1;
            int nE = dfs(adj, vis, i, nV); // Finding the sum of degrees of all edges
            nE = nE / 2;                   // according to handshaking lemma the number of edges is equal to number of degrees/2
            // nE = max(nE, 1LL);
            // cout << nE << " " << nV << endl;
            if (nE != nV)
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}