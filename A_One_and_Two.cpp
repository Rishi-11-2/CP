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
    int arr[n];
    int c_2 = 0;
    int c_1 = 0;
    int s = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 2)
            c_2++;
        s = s * arr[i];
    }
    if (c_2 % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }
    if (s == 1)
    {
        cout << 1 << endl;
        return;
    }
    int d = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == 2)
        {
            d++;
        }
        if (d == (c_2 / 2))
        {
            cout << (i + 1) << endl;
            return;
        }
    }
    cout << -1 << endl;
}