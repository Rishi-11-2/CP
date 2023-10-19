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
    solve();
}
void solve()
{
    int n, x;
    cin >> n >> x;
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        m[x.substr(3)] += 1;
    }
    int res = 0;
    for (int i = 0; i < x; i++)
    {
        string x1;
        cin >> x1;
        if (m[x1] != 0)
        {
            res += m[x1];
            m[x1] = 0;
        }
    }
    cout << res;
}