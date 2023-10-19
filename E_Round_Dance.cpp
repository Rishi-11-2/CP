#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int f = 0;
void dfs(set<int> adj[], vector<int> &vis, int s)
{
    vis[s] = 1;
    // cout<<s<<endl;
    if (adj[s].size() == 1)
    {
        // cout << "hi" << endl;
        f = 1;
    }
    for (int v : adj[s])
    {
        if (vis[v] == 0)
        {
            dfs(adj, vis, v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    set<int> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        adj[i].insert(arr[i - 1]);
        adj[arr[i - 1]].insert(i);
    }
    vector<int> vis(n + 1, 0);
    int c = 0;
    int d = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            f = 0;
            dfs(adj, vis, i);
            if (f == 1)
                d++;
            c++;
        }
    }
    // cout << d << endl;
    if (d > 0)
        d--;
    cout << c - d << " " << c << endl;
    f = 0;
}