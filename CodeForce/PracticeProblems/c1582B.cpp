// https://codeforces.com/contest/1582/problem/B
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
    int n;
    cin >> n;
    int arr[n];
    int flag = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
            flag += 1;
        if (arr[i] == 0)
            count++;
    }
    if (flag == 0)
    {
        cout << 0 << el;
        return;
    }
    else if (count == 0)
    {
        cout << flag << el;
    }
    else
    {
        cout << ((flag) * (1ll << count)) << el;
        // using 1ll to avoid overflow as 1 is in int;
    }
}