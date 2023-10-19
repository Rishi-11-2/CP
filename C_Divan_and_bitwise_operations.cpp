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
    long long a = 0;
    for (long long i = 0; i < m; i++)
    {
        long long x, y, z;
        cin >> x >> y >> z;
        a |= z;
    }
    long long b = (n - 1) * 1LL;
    long long res = 1LL;
    long long x = 2LL;
    long long mod = (long long)(1e9 + 7);
    while (b > 0)
    {
        if (b & 1)
            res = ((res % mod) * (x % mod)) % mod;
        x = ((x % mod) * (x % mod)) % mod;
        b >>= 1;
    }
    // cout << a << " " << res << endl;
    long long t = ((a % mod) * (res % mod)) % mod;
    cout << t << endl;
}