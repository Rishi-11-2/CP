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
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0;
    int b = 0;
    int res = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            b = 0;
            len++;
        }
        if (s[i] == '0')
        {
            b++;
        }
        if (b > 1)
        {
            res = max(res, len);
            len = 0;
        }
    }
    res = max(res, len);
    cout << res << endl;
}