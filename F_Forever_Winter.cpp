#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
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
    map<int, int> m1;
    for (int i = 1; i <= n; i++)
    {
        vector<int> v = adj[i];
        if (v.size() != 1)
        {
            int bg = v.size();
            m1[bg] += 1;
        }
    }
    int x1 = 0;
    int y1 = 0;
    for (auto &it : m1)
    {
        if (it.second > 1)
        {
            y1 = it.first - 1;
        }
        else if (it.second == 1)
            x1 = it.first;
    }
    if (y1 == 0)
        y1 = x1 - 1;
    if (x1 == 0)
        x1 = y1 + 1;
    cout << x1 << " " << y1 << endl;
}