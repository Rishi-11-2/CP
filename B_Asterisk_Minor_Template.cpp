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
    // cout << "hi" << endl;
    string s1, s2;
    cin >> s1 >> s2;
    if (s1[0] == s2[0])
    {
        cout << "YES" << endl;
        cout << s1[0] << "*" << endl;
    }
    else if (s1[s1.length() - 1] == s2[s2.length() - 1])
    {
        cout << "YES" << endl;
        cout << "*" << s1[s1.length() - 1] << endl;
    }
    else
    {
        int n1 = s1.length();
        int n2 = s2.length();
        for (int i = 0; i < n1; i++)
        {
            string x = s1.substr(i, 2);
            for (int j = 0; j < n2; j++)
            {
                string y = s2.substr(j, 2);
                if (x == y)
                {
                    cout << "YES" << endl;
                    cout << "*" << x << "*" << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
    }
}