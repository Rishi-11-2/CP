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
    int maxM = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxM = max(maxM, arr[i]);
    }
    int x = log2(maxM);
    x++;
    int h = 0;
    for (int i = 0; i <= x; i++)
    {
        h = 0;
        for (int j = 0; j < n; j++)
        {
            if ((arr[i] & (1 << i)) != 0)
                h++;
        }
        if (h == n)
        {
            cout << 0 << endl;
            return;
        }
    }
}