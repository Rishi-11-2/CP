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
    int arr[n][m];
    if (m == 1)
    {
        cout << 0 << endl;
        for (int i = 0; i < n; i++)
            cout << 0 << endl;
        return;
    }
    else if (n == 1)
    {
        cout << 2 << endl;
        for (int i = 0; i < m; i++)
            cout << i << " ";
        cout << endl;
        return;
    }
    vector<int> v(m, 0);
    for (int i = 0; i < m; i++)
    {
        v[i] = i;
    }
    auto original = v;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = v[j];
        }
        count++;
        if (count == m - 1)
        {
            count = 0;
            v = original;
        }
        else
        {
            int x = v[0];
            for (int j = 1; j < m; j++)
            {
                v[j - 1] = v[j];
            }
            v[m - 1] = x;
        }
    }
    cout << min(n + 1, m) << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}