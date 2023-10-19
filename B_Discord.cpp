#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> x;
    vector<vector<int>> a(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            // cout << a[i][j] << " ";
            x[{a[i][j], a[i][j + 1]}] = 1;
            x[{a[i][j + 1], a[i][j]}] = 1;
        }
        // cout << endl;
    }
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (x[{i, j}] == 0)
            {
                // cout << i << " " << j << endl;
                c++;
                x[{i, j}] = 1;
                x[{j, i}] = 1;
            }
        }
    }
    cout << c << endl;
}