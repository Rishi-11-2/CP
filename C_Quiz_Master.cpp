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
vector<int> factorial[100005];
void solve();
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init();
    for (int i = 1; i <= 100000; i++)
    {
        for (int j = i; j <= 100000; j += i)
        {
            factorial[j].push_back(i);
        }
    }
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
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i].first = x;
        arr[i].second = i;
    }
    sort(all(arr));
    vector<int> f(m + 5, 0);
    int curr_count = 0;
    int j = 0;
    int res = INT64_MAX;
    for (int i = 0; i < n; i++)
    {
        for (auto it : factorial[arr[i].first])
        {
            if (it > m)
                break;
            if (!f[it]++)
            {
                curr_count++;
            }
        }
        while (curr_count == m)
        {
            int curr_size = arr[i].first - arr[j].first;
            if (curr_size < res)
                res = curr_size;
            for (auto it : factorial[arr[j].first])
            {
                if (it > m)
                    break;
                if (--f[it] == 0)
                {
                    curr_count--;
                }
            }
            // cout << j << endl;
            j++;
        }
    }
    if (res == INT64_MAX)
        cout << -1 << endl;
    else
        cout << res << endl;
}