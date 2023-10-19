#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
bool flag = 0;
void dfs(vector<string> &s, string t, int k, int i, int j, int n, int m, vector<pair<int, int>> &v, int q)
{
    if (flag == 1)
        return;
    if (k == 5)
    {
        // reverse(all(v));
        for (auto &it : v)
        {
            cout << it.first << " " << it.second << endl;
        }
        flag = 1;
    }

    for (int z = 0; z < 9; z++)
    {
        int x = a[z] + i;
        int y = b[z] + j;
        int flag1 = 0;
        if (q == -1)
            flag1 = 1;
        if (q == z || q == -1)
        {
            if (x >= 0 && y >= 0 && x < n && y < m)
            {
                if (s[x][y] == t[k])
                {
                    if (q == -1)
                    {
                        q = z;
                    }
                    // cout << x << " " << y << endl;
                    v.push_back({x + 1, y + 1});
                    dfs(s, t, k + 1, x, y, n, m, v, q);
                }
            }
            if (flag1 = 1)
                q = -1;
        }
    }
}
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
    string z = "snuke";
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 's')
            {
                vector<pair<int, int>> v;
                v.push_back({i + 1, j + 1});
                int a[] = {0, 0, 1, -1, 1, 1, -1, -1};
                int b[] = {1, -1, 0, 0, 1, -1, -1, 1};
                
            }
        }
    }
}