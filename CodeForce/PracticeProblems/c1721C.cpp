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
    int a[n];
    int b[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int d_min[n];
    int d_max[n];
    int low1 = 0;
    int low2 = 0;
    while (low1 < n)
    {
        auto it = lower_bound(b, b + n, a[low1]) - b;
        d_min[low1] = b[it] - a[low1];
        low1++;
    }
    low2 = n - 1;
    int high2 = n - 1;
    while (low2 >= 0)
    {
        // auto it = lower_bound(b, b + n, a[low2]) - b;
        // d_max[low2] = b[high2] - a[low2];
        // auto it1 = upper_bound(a, a + n, b[low2]) - a;
        // d_max[low2] = b[it1 - 1] - a[low2];

        // if (it == high2)
        //     high2--;

        // low2++;
        d_max[low2] = b[high2] - a[low2];
        if (a[low2] > b[high2 - 1])
        {
            high2--;
        }
        low2--;
    }
    for (int i = 0; i < n; i++)
        cout << d_min[i] << " ";
    cout << el;
    for (int i = 0; i < n; i++)
        cout << d_max[i] << " ";
    cout << el;
}