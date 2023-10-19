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
void solve();
int32_t main()
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
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n;
    cin >> n;
    int a[2];
    a[0] = 0;
    a[1] = 0;
    int i = 2;
    a[0] += 1;
    n = n - 1;
    int c = 1;
    int d = 0;
    while (n > 0)
    {
        // cout << c << endl;
        a[c] += min(n, i);
        d++;
        n -= i;
        i++;
        if (d == 2)
        {
            d = 0;
            c = (c + 1) % 2;
        }
    }
    cout << a[0] << " " << a[1] << endl;
}