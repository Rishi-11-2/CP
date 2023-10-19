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
    long long n;
    cin >> n;
    long long maxm = 0;
    map<long long, long long> mp;
    long long mod = 998244353;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        mp[x]++;
        maxm = max(maxm, x);
    }

    long long k = mp[maxm - 1];
    long long f = mp[maxm];
    // if (k == 0 && f != n)
    // {
    //     cout << 0 << endl;
    //     return;
    // }
    long long x = 1;
    long long y = 1;
    for (long long i = 1; i <= n; i++)
    {
        x = (x % mod * (i % mod)) % mod;
        if (i != (k + 1))
            y = (y % mod * (i % mod)) % mod;
    }
    // cout << x << endl;
    if (f == 1)
    {
        x = (x - y + mod) % mod;
    }
    cout << x << endl;
}