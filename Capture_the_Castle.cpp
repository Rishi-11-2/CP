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
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> v;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        vector<char> c;
        for (int j = 0; j < n; j++)
        {
            char c1;
            cin >> c1;
            if (c1 == 'D')
            {
                q.push({i, j});
            }
            c.push_back(c1);
        }
        v.push_back(c);
    }
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int a = it.first;
        int b = it.second;
        if (a - 1 >= 0)
        {
            if (v[a - 1][b] == 'L')
            {
                v[a - 1][b] = 'D';
                q.push({a - 1, b});
            }
        }
        if (b - 1 >= 0)
        {
            if (v[a][b - 1] == 'L')
            {
                v[a][b - 1] = 'D';
                q.push({a, b - 1});
            }
        }
        if (a + 1 < n)
        {
            if (v[a + 1][b] == 'L')
            {
                v[a + 1][b] = 'D';
                q.push({a + 1, b});
            }
        }
        if (b + 1 < n)
        {
            if (v[a][b + 1] == 'L')
            {
                v[a][b + 1] = 'D';
                q.push({a, b + 1});
            }
        }
    }
    int flag = 0;
    for (auto it : v)
    {
        for (auto iter : it)
        {
            if (iter == 'L')
            {
                flag = 1;
            }
        }
    }
    if (flag == 1)
        cout << 0 << endl;
    else
        cout << 1 << endl;
}