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

    solve();
}
long long mod = 998244353;
long long binPow(long long x, long long y)
{
    long long res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
void solve()
{
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    map<long long, long long> mp1;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        mp1[arr[i]] = x;
    }
    long long m;
    cin >> m;
    long long b[m];
    for (long long i = 0; i < m; i++)
        cin >> b[i];
    map<long long, long long> mp2;
    for (long long i = 0; i < m; i++)
    {
        long long y;
        cin >> y;
        mp2[b[i]] = y;
    }
    for (long long i = 0; i < m; i++)
    {

        long long y = mp2[b[i]];
        if (mp1[b[i]] < y)
        {
            cout << 0 << endl;
            return;
        }
        mp1[b[i]] -= y;
    }
    long long count = 0;
    for (auto it : mp1)
    {
        if (it.second != 0)
            count++;
    }

    cout << binPow(2, count) << endl;
}