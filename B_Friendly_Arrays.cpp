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
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    vector<int> count(33, 0);
    for (int i = 0; i <= 32; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((a[j] & (1 << i)) == 0)
            {
                count[i]++;
            }
        }
    }
    vector<int> vis(33, 0);
    
}