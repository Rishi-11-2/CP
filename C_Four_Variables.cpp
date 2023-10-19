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
int countDivisors(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}
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
    vector<pair<int, int>> v;
    // map<int, int> m;
    for (int i = 1; i < n; i++)
    {
        int x = n - i;
        v.push_back({i, x});
    }
    long long res = 0;
    for (auto &it : v)
    {
        int a = 1;
        int b = 1;
        if (it.first != 1)
        {
            //  cout << countDivisors(3);
            int a1 = countDivisors(it.first) - 1;
            if (a1 == 1)
                a = 2;
            else
                a = ((a1 * (a1 - 1)));
            if (it.first % 2 == 0)
                a = a - 1;
        }
        if (it.second != 1)
        {
            int a2 = countDivisors(it.second) - 1;
            if (a2 == 1)
                b = 2;
            else
                b = ((a2) * (a2 - 1));
            if (it.second % 2 == 0)
            {
                b = b - 1;
            }
        }
        res += a * b;
    }
    cout << res << endl;
}