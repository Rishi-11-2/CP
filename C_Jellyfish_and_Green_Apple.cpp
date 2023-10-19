#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
bool ispow(int n)
{
    while (n != 1)
    {
        if (n % 2 != 0)
            return 0;
        n = n >> 1;
    }
    return 1;
}
void solve()
{
    long long n, m;
    cin >> n >> m;
    long long count = 0LL;
    long long i = n;
    long long x = n;
    while (x < m)
    {
        x = x * (2 * 1LL);
    }
    long long y = __gcd(n, m);
    int z = m / y;
    if (!ispow(z))
    {
        cout << -1 << endl;
        return;
    }
    while (true)
    {
        if (i == m)
        {
            break;
        }
        i = i % m;
        // cout << i << endl;
        if (i == 0)
            break;
        while (i < m)
        {
            count += i * 1LL;
            i = (i * (2 * 1LL));
        }
    }
    cout << count << endl;
}