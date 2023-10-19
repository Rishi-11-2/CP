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
    long long m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    long long x = m / k;
    if (ak > 0 && m > 0)
    {
        m -= min(x, ak) * k;
    }
    long long req = (long long)(1e9);
    long long z = (long long)(1e9);
    if (m - k <= a1 && m >= k)
    {
        req = 1LL;
    }
    if (a1 > 0 && m > 0)
    {
        m -= min(m, a1);
    }
    if (m == 0)
        z = 0;
    else if (m > 0)
    {
        long long g = m / k;
        m -= g * k;
        z = g + m;
    }

    cout << min(z, req) << endl;
}