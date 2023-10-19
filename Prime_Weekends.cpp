#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define all(v) (v).begin(), (v).end()
#define int long long int
#define lld long double
vector<int> Primes(10000000, -1);
vector<int> pp(10000000, 0);
int c = 0;
void SieveOfEratosthenes(int n)
{
    Primes[0] = 1;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (Primes[i / 2] == 0)
        {
            for (int j = 3 * i; j <= n; j += 2 * i)
                Primes[j / 2] = 1;
        }
    }
}
void solve();
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    SieveOfEratosthenes(10000002);

    for (int i = 0; i <= 10000000; i++)
    {
        if (Primes[i] != -1)
            cout << Primes[i] << endl;
    }
    // cout << c << endl;
    pp[0] = Primes[0];
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        int s = pp[y] - pp[x];
        // cout << pp[10000001] - s << endl;
    }
    cout << c << endl;
}