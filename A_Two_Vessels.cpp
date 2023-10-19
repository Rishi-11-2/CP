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
    int a, b, c;
    cin >> a >> b >> c;
    int z = abs(b - a);
    int x = z / 2;
    if (z % 2)
        x++;
    int y = x / c;
    // cout << x << endl;
    if (x % c)
        y++;
    cout << y << endl;
}