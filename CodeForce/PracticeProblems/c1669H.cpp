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
    vector<int> c(31);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 30; j >= 0; j--)
        {
            if (arr[i] & (1 << j))
                c[j]++;
        }
    }
    int s = 0;
    for (int j = 30; j >= 0; j--)
    {
        int need = n - c[j];
        if (need <= k)
        {
            k -= need;
            s += (1 << j);
        }
    }
    cout << s << el;
}