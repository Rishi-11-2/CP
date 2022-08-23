// https://codeforces.com/contest/1606/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define int long long int
#define lld long double
#define INF INT_MAX
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
    if (k == 1)
    {
        cout << n - 1 << el;
        return;
    }
    if (n <= 2)
    {
        cout << 1 << el;
        return;
    }
    int i = 1;
    int count = 0;
    while (i < k)
    {
        i = i * 2;
        count++;
    }
    if (i < n)
    {
        count += (n - i + k - 1) / k;
    }
    cout << count << el;
}