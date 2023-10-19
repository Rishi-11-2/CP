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
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]] += 1;
    }
    int maxm = 0;
    for (auto it : m)
    {
        maxm = max(maxm, it.second);
    }
    if (maxm == 4)
    {
        cout << -1 << endl;
        return;
    }
    else if (maxm == 3)
    {
        cout << 6 << endl;
        return;
    }
    else if (maxm == 2)
    {
        cout << 4 << endl;
        return;
    }
    else
    {
        cout << 4 << endl;
        return;
    }
}