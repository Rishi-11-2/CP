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
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int c1 = 0;
    int c2 = 0;
    for (int i = 1; i < n; i++)
    {
        if (s1[i] == s1[i - 1])
            c1 += 1;
        if (i >= 2 && s1[i] == s1[i - 2] && s1[i] == s1[i - 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 1; i < m; i++)
    {
        if (s2[i] == s2[i - 1])
            c2 += 1;
        if (i >= 2 && (s2[i] == s2[i - 2]) && (s2[i] == s2[i - 1]))
        {
            cout << "NO" << endl;
            return;
        }
    }
    if (c1 >= 1 && c2 >= 1)
    {
        cout << "NO" << endl;
    }
    else if (c1 > 1 || c2 > 1)
    {
        cout << "NO" << endl;
    }
    else if (c1 == 1 || c2 == 1)
    {
        if (s1[n - 1] != s2[m - 1])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else if (c1 == 0 && c2 == 0)
    {
        cout << "YES" << endl;
    }
}