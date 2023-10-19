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
    int c_o = 0;
    int c_t = 0;
    multiset<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x <= 1)
            c_o++;
        if (x > 1)
            c_t++;
        s.insert({x, i + 1});
    }
    if (c_o > 0 && c_t > 0)
    {
        cout << -1 << endl;
        return;
    }
    else if (c_o == n || n == 1)
    {
        cout << 0 << endl;
        return;
    }
    auto it = s.end();
    it--;
    auto i = s.begin();
    vector<pair<int, int>> v;
    while ((*it).first != (*i).first)
    {
        s.erase(it);
        s.erase(i);
        v.push_back({(*it).second, (*i).second});
        s.insert({(*i).first, (*i).second});
        int x = ((*it).first / (*i).first);
        if ((((*it).first) % ((*i).first)) != 0)
        {
            x++;
        }
        // cout << x << endl;
        s.insert({x, (*it).second});
        it = s.end();
        it--;
        i = s.begin();
    }
    cout << v.size() << endl;
    for (auto &it : v)
    {
        cout << it.first << " " << it.second << endl;
    }
}