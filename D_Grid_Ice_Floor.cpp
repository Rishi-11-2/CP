#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
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
    vector<vector<char>> grid(n + 1, vector<char>(m + 1, '/'));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    queue<vector<int>> q;
    q.push({2, 2});
    int count = 1;
    int a[] = {-1, 1, 0, 0};
    int b[] = {0, 0, -1, 1};
    pair<int, int> dir = {a[0], b[0]};
    vis[2][2] = 1;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int i = it[0];
        int j = it[1];
        int x = i + dir.first;
        int y = j + dir.second;
        int flag = 0;
        if (x >= 0 && y >= 0 && x <= n && y <= m)
        {
            if (vis[x][y] == 0 && grid[x][y] == '.')
            {
                count++;
                flag = 1;
                q.push({x, y});
                vis[x][y] = 1;
            }
        }
        if (!flag)
        {
            int flag2 = 0;
            for (int k = 0; k < 4; k++)
            {
                pair<int, int> cc = {a[k], b[k]};
                if (cc == dir)
                    continue;
                int x = i + a[k];
                int y = j + b[k];
                if (x >= 0 && y >= 0 && x <= n && y <= m)
                {
                    if (vis[x][y] == 0 && grid[x][y] == '.')
                    {
                        count++;
                        flag = 1;
                        q.push({x, y});
                        vis[x][y] = 1;
                        dir = cc;
                        flag2 = 1;
                        break;
                    }
                }
            }
            if (!flag2)
            {
                cout << count << endl;
                return;
            }
        }
    }
}