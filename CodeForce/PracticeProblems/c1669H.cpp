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
    int arr[n];
    int z = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        z = z & arr[i];
    }
    if (k == 0)
    {
        cout << z << el;
        return;
    }
    else if (n == 1)
    {
        int s = arr[0];
        int y = pow(2, 30);
        for (int i = 1; i <= k; i++)
        {
            s = s | y;
            y = pow(2, 30 - i);
        }
        cout << s << el;
        return;
    }
    else
    {
        int t = k;
        int y = pow(2, 30);
        for (int i = 1; i <= k; i++)
        {
            int j = 0;
        }
    }
}