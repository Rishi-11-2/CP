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
#define ll long long int
#define lld long double
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<pair<int, int>> v(m);
    int minM = INT32_MAX;
    int minZ = INT32_MAX;
    unordered_map<int, int> h;
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].first >> v[i].second;
        h[v[i].first] += 1;
        h[v[i].second] += 1;
        minM = min(minM, a[v[i].first] + a[v[i].second]);
    }
    if (m == 0 or m % 2 == 0)
    {
        cout << 0 << el;
    }
    else if (m == 1)
    {
        cout << min(a[v[0].first], a[v[0].second]) << el;
    }
    else
    {
        int flag = -1;
        for (int i = 1; i < n + 1; i++)
        {
            if (h[i] % 2 != 0)
            {
                minZ = min(minZ, a[i]);
            }
        }
        cout << min(minM, minZ) << el;
    }
}