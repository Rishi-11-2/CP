#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int res = 0;
int s = 0;
void dfs(vector<vector<int>> &v, vector<vector<int>> &vis, int i, int j, int n, int m)
{
    vis[i][j] = 1;
    int a[] = {1, -1, 0, 0};
    int b[] = {0, 0, 1, -1};
    int flag = 0;
    for (int k = 0; k < 4; k++)
    {
        if ((i + a[k]) < n && (i + a[k]) >= 0 && (j + b[k]) < m && (j + b[k]) >= 0)
        {
            if (vis[i + a[k]][j + b[k]] == 0 && v[i + a[k]][j + b[k]] != 0)
            {
                flag = 1;
                // cout << v[i + a[k]][j + b[k]] << " ";

                s += (v[i + a[k]][j + b[k]]);
                // cout << s << endl;
                dfs(v, vis, i + a[k], j + b[k], n, m);
            }
        }
    }
    if (flag == 0)
    {
        // cout << v[i][j] << " ";
        res = max(s, res);
        // s = 0;
        return;
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
        res = 0;
        solve();
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && v[i][j] != 0)
            {
                s = 0;
                s += (v[i][j]);
                dfs(v, vis, i, j, n, m);
            }
        }
    }
    cout << res << endl;
}