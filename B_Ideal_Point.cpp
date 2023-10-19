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
bool mycomp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
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
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    int c_k = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (k >= x && k <= y)
            c_k++;
        v.push_back({x, y});
    }
    if (c_k == 0)
    {
        cout << "NO" << endl;
        return;
    }
    // sort(v.begin(), v.end(), mycomp);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        for (int k = v[i].first; k <= v[i].second; k++)
        {
            m[k]++;
        }

        // prev = v[i].second;
    }
    vector<int> f;
    for (auto &it : m)
    {
        if (it.second >= c_k && it.first != k)
        {
            f.push_back(it.first);
        }
    }
    // cout << c_k << endl;
    // for (auto it : f)
    // {
    //     cout << it << " ";
    // }
    // cout << ele << " " << elf << endl;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (auto it : f)
        {
            if (it >= v[i].first && it <= v[i].second)
            {
                if (m[it] >= c_k)
                {
                    m[it]--;
                    flag = 1;
                }
            }
        }
        if (flag == 1 && k >= v[i].first && k <= v[i].second)
        {
            c_k--;
        }
    }
    // if (c_k == 0)
    // {
    //     cout << "NO" << endl;
    //     return;
    // }
    for (auto it : f)
    {
        // cout << it << endl;
        if (m[it] >= c_k)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}