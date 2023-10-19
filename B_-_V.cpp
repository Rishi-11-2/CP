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
    solve();
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    int g = 0;
    stack<int> s;
    vector<int> v;
    int idx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[idx] == i)
        {
            s.push(i);
            g = 0;
            idx++;
        }
        else if (arr[idx] != i)
        {
            if (g == 0)
            {
                s.push(i);
                g = 1;
                while (!s.empty())
                {
                    v.push_back(s.top());
                    s.pop();
                }
            }
            else
            {
                v.push_back(i);
            }
        }
    }
    for (auto &it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}