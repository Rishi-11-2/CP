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
    int l, r, m;
    cin >> l >> r >> m;
    int x = m + r - l;
    int y = m - r + l;
    for (int i = l; i <= r; i++)
    {
        int n1 = x / i;
        int x1 = m - (n1 * i);
        if ((n1 * i) >= y && (n1 * i) <= x && x1 <= 0 && x1 >= (l - r))
        {
            cout << i << " " << x1 + l << " " << x1 << endl;
            break;
        }
    }
}