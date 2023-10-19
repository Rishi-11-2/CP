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
int flag = 0;
map<pair<string, string>, int> dp;
int gen(string s, string n, string m)
{
    if (dp[{s, n}] == 0)
    {
        if (s.length() == 0)
        {
            if (n == m)
            {
                dp[{s, n}] = 1;
                return 1;
            }
            dp[{s, n}] = -1;
            return -1;
        }
        char x = s[0];
        s = s.substr(1);
        if (gen(s, x + n, m) == 1)
        {
            dp[{s, n}] = 1;
            return dp[{s, n}];
        }
        dp[{s, n}] = gen(s, n + x, m);
        return dp[{s, n}];
    }
    return dp[{s, n}];
}
void solve(int c);
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int x = 1;
    while (t--)
    {
        solve(x++);
    }
}
void solve(int c)
{
    int n;
    cin >> n;
    string s, m;
    cin >> s >> m;
    int x = gen(s, "", m);
    if (dp[{"", m}] == 1)
        cout << "Case " << c << ":"
             << " YES" << endl;
    else
        cout << "Case " << c << ":"
             << " NO" << endl;
    flag = 0;
}