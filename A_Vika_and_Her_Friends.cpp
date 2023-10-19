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
    int n, m, k;
    cin >> n >> m >> k;
    int grid[n + 1][m + 1];
    memset(grid, 0, sizeof(grid));

    int x, y;
    cin >> x >> y;
    grid[x][y] = 2;

    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        grid[a][b] = 1;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << grid[i][j] << " ";
    //     cout << endl;
    // }
    int a1 = x + 1;
    int a2 = y + 1;
    int f1 = 1;
    int g = 0;
    int flag = 0;
    while (a1 <= n && a2 <= m)
    {
        if (grid[a1][a2] == 1)
        {
            f1 = 0;
            g++;
            break;
        }
        flag = 1;
        a1++;
        a2++;
    }
    a1 = x + 1;
    a2 = y - 1;
    int f2 = 1;
    flag = 0;
    while (a1 <= n && a2 >= 1)
    {
        if (grid[a1][a2] == 1)
        {
            f2 = 0;
            g++;
            break;
        }
        flag = 1;
        a1++;
        a2--;
    }
    if (flag == 0)
    {
        v++;
    }
    int f3 = 1;
    a1 = x - 1;
    a2 = y + 1;
    flag = 0;
    while (a1 >= 1 && a2 <= m)
    {
        if (grid[a1][a2] == 1)
        {
            f3 = 0;
            g++;
            break;
        }
        flag = 1;

        a1--;
        a2++;
    }
    if (flag == 0)
    {
        f3 = 0;
        v++;
    }
    int f4 = 1;
    a1 = x - 1;
    a2 = y - 1;
    flag = 0;
    while (a1 >= 1 && a2 >= 1)
    {
        if (grid[a1][a2] == 1)
        {
            f4 = 0;
            g++;
            break;
        }
        flag = 1;
        a1--;
        a2--;
    }
    if (flag == 0)
    {
        f4 = 0;
        // g++;
        v++;
    }
    a1 = x;
    a2 = y - 1;
    int h1 = 1;
    int h2 = 1;
    int h3 = 1;
    int h4 = 1;
    while (a2 >= 1)
    {
        if (grid[a1][a2] == 1)
        {
            h1 = 0;
            g++;
            break;
        }
        a2--;
    }
    a1 = x - 1;
    a2 = y;
    flag = 0;
    while (a1 >= 1)
    {
        if (grid[a1][a2] == 1)
        {
            h2 = 0;
            g++;
            break;
        }
        a1--;
    }
    a1 = x;
    a2 = y + 1;
    flag = 0;
    while (a2 <= m)
    {
        if (grid[a1][a2] == 1)
        {
            h3 = 0;
            g++;
            break;
        }
        flag = 1;
        a2++;
    }
    a1 = x + 1;
    a2 = y;
    while (a1 <= n)
    {
        if (grid[a1][a2] == 1)
        {
            h4 = 0;
            g++;
            break;
        }
        a1++;
    }

    if (g >= 4)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}