#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int wt = 0;
int z = 0;
void dfs(vector<int> adj[], int s, vector<int> &vis, int p, map<pair<int, int>, int> &m)
{
    z = z + 1;
    vis[s] = 1;
    if (m[{p, s}] == 1)
    {
        m[{p, s}] = 0;
    }
    for (int v : adj[s])
    {
        if (m[{s, v}] == 1)
        {
            m[{s, v}] = 0;
        }
        if (vis[v] == 0)
        {
            dfs(adj, v, vis, p, m);
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
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> adj[27];
    map<pair<int, int>, int> m;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
            continue;
        if (s2[i] < s1[i])
        {
            cout << -1 << endl;
            return;
        }
        adj[s1[i] - 'a'].push_back((s2[i] - 'a'));
        m[{(s1[i] - 'a'), (s2[i] - 'a')}] = 1;
    }
    int res = 0;
    vector<int> vis(27, 0);
    for (int i = 0; i < n; i++)
    {
        int x = s1[i] - 'a';
        int y = s2[i] - 'a';
        if (m[{x, y}] == 1)
        {
            // cout << x << " " << y << endl;
            // wt++;
            z = 0;
            dfs(adj, y, vis, x, m);
            wt += z;
        }
    }
    cout << wt << endl;
    wt = 0;
}