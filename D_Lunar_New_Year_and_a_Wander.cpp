#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));

    solve();
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
    vector<int> res;
    vector<int> vis(n + 1, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    vis[1] = 1;
    while (!pq.empty())
    {
        int u = pq.top();
        res.push_back(u);
        pq.pop();
        for (int v : adj[u])
        {
            if (vis[v] == 0)
            {
                pq.push(v);
                vis[v] = 1;
            }
        }
    }
    vector<pair<int,int>>v;
    // for(auto [a,b]:v)
    // {
    //     cout<<a<<" "<<b<<endl;
    // }
    for (auto it : res)
        cout << it << " ";
    cout << endl;
}