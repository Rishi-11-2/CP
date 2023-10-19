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
int fib[100005];
void computeFibonacci()
{
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 100005; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}
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
    string s;
    cin >> s;
    // int c = 0;
    char a = s[0];
    char b = s[1];
    map<string, int> m;
    int c = 1;
    for (int i = 2; i < n; i++)
    {
        if (s[i] == a)
        {
            a = b;
            b = s[i];
            continue;
        }
        // else if (s[i] == b)
        // {
        //     string z = "";
        //     string a1 = "";
        //     if (i >= 1)
        //     {
        //         a1 = s.substr(0, i);
        //     }
        //     z = a1 + s.substr(i + 2);
        //     if (m[z] == 0)
        //     {
        //         c++;
        //         m[z] = 1;
        //     }
        // }
        a = b;
        b = s[i];
        c++;
    }
    cout << c << endl;
}