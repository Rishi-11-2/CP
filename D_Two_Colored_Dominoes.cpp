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
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'U' || v[i][j] == 'D')
            {
                count++;
                if (flag % 2 == 0 && i % 2 == 0)
                {
                    v[i][j] = 'W';
                    flag++;
                }
                else if (flag % 2 != 0 && (i % 2) == 0)
                {
                    v[i][j] = 'B';
                    flag++;
                }
                else if (flag % 2 == 0 && i % 2 != 0)
                {
                    v[i][j] = 'B';
                    flag++;
                }
                else if (flag % 2 != 0 && i % 2 != 0)
                {
                    v[i][j] = 'W';
                    flag++;
                }
            }
        }
        if (count % 2)
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int j = 0; j < m; j++)
    {
        int count = 0;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i][j] == 'L' || v[i][j] == 'R')
            {
                count++;
                if ((flag % 2) == 0 && (j % 2) == 0)
                {
                    v[i][j] = 'W';
                    flag++;
                }
                else if ((flag % 2) != 0 && (j % 2) == 0)
                {
                    v[i][j] = 'B';
                    flag++;
                }
                else if ((flag % 2) == 0 && (j % 2) != 0)
                {
                    v[i][j] = 'B';
                    flag++;
                }
                else if (flag % 2 != 0 && j % 2 != 0)
                {
                    v[i][j] = 'W';
                    flag++;
                }
            }
        }
        if (count % 2)
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << v[i][j];
        cout << endl;
    }
}