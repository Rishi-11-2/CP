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
    int vis[n+1][m+1][4];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for(int k=0;k<4;k++)
            {
                vis[i][j][k]=0;
            }
            cin >> grid[i][j];
        }
    }
    queue<vector<int>> q;
    int count = 0;
    int a[] = {-1, 1, 0, 0};
    int b[] = {0, 0, -1, 1};
    for(int k=0;k<4;k++)
    {
        vis[2][2][k] = 1;
        q.push({2,2,k});
    }
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int i = it[0];
            int j = it[1];
            int dir=it[2];
            int x = i + a[dir];
            int y = j + b[dir];
            int flag = 0;
            if (x >= 1 && y >= 1 && x <= n && y <= m)
            {
                if (vis[x][y][dir] == 0 && grid[x][y] == '.')
                {
                    flag = 1;
                    q.push({x, y,dir});
                    vis[x][y][dir] = 1;
                }
            }
            if (!flag && grid[x][y]=='#')
            {
                for (int k1 = 0; k1 < 4; k1++)
                {
                    int x = i + a[k1];
                    int y = j + b[k1];
                    if (x >= 1 && y >= 1 && x <= n && y <= m)
                    {
                        if (vis[x][y][k1] == 0 && grid[x][y] == '.')
                        {
                            q.push({x, y,k1});
                            vis[x][y][k1] = 1;
                            // break;
                        }
                    }
                }
            }
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int flag=0;
            for(int k=0;k<4;k++)
            {
                if(vis[i][j][k]==1)
                flag=1;
            }
            if(flag)
            count++;
        }
    }
       
    cout<<count<<endl;
}