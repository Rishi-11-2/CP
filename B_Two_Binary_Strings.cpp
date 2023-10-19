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
    string a, b;
    cin >> a >> b;
    int n = a.length();
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == '0' && b[i] == '0')
        {
            if (a[i + 1] == '1' && b[i + 1] == '1')
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}