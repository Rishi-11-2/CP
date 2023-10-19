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
int countWithOddSetBits(int n)
{
    // If n is odd, then half of the
    // integers in (0, 1, .. n) contain
    // odd number of set bits.
    if (n % 2 != 0)
        return (n + 1) / 2;

    // If n is even, we know result for
    // n-1. We explicitly compute set bit
    // count in n.
    int count = __builtin_popcount(n);

    int ans = n / 2;
    if (count % 2 != 0)
        ans++;
    return ans;
}
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
}
void solve()
{
    int n;
    cin >> n;
    int c = countWithOddSetBits(n);
    cout << n - c + 1 << endl;
}