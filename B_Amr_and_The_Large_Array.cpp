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
bool myCmp(pair<int, int> a, pair<int, int> b)
{
    int x = a.second - a.first;
    int y = b.second - b.first;
    return x < y;
}
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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> m;
    int maxf = 0;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
        maxf = max(maxf, m[arr[i]]);
    }
    map<int, int> m1;
    map<int, int> m3;
    // int minM = INT_MAX;
    // cout << maxf << endl;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        m3[arr[i]]++;
        if (m[arr[i]] == maxf)
        {
            if (m1[arr[i]] != 0 && m3[arr[i]] == maxf)
            {
                // cout << "HI" << endl;
                v.push_back({m1[arr[i]], i + 1});
                // cout << m[arr[i]] << " " << i << " " << endl;
            }
            else if (m1[arr[i]] == 0)
            {
                m1[arr[i]] = i + 1;
            }
        }
    }
    if (v.size() != 0)
    {
        sort(all(v), myCmp);

        cout << v[0].first << " " << v[0].second << endl;
    }
    else
    {
        cout << 1 << " " << 1 << endl;
    }
}