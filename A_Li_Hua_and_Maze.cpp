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
    long long n, m;
    cin >> n >> m;
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    int res = 4;
    if (a == n || a == 1)
        res--;
    if (b == m || b == 1)
        res--;
    int res1 = 4;
    if (c == 1 || c == n)
        res1--;
    if (d == 1 || d == m)
        res1--;
    cout << min(res, res1) << endl;
}