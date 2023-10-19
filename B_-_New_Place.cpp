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

#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    map<string, int> m;
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    string x = "";
    for (int i = 0; i < n; i++)
    {
        x += b[i];
        m[x] = 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        string y = a.substr(i);
        if (m[y] == 1)
            break;
        else
        {
            res++;
        }
    }
    cout << res;
}