#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n][m];
        int maxM = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int s = 0;
                int x = i;
                int y = j;
                while ((x <= (n - 1)) and (y <= (m - 1)))
                {
                    s += a[x][y];
                    x += 1;
                    y += 1;
                }
                x = i;
                y = j;
                while ((x >= 0) and (y >= 0))
                {
                    s += a[x][y];
                    x--;
                    y--;
                }
                x = i;
                y = j;
                while ((x >= 0) and (y <= (m - 1)))
                {
                    s += a[x][y];
                    x--;
                    y++;
                }
                x = i;
                y = j;
                while ((y >= 0) and (x <= (n - 1)))
                {
                    s += a[x][y];
                    y--;
                    x++;
                }
                s -= (3 * (a[i][j]));

                maxM = max(s, maxM);
            }
        }
        cout << maxM << endl;
    }
}