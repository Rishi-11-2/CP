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
    int n;
    cin >> n;
    int a = 0, b = 0, c = 101, d = 101;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        a = max(a, v[i].first);
        b = max(b, v[i].second);
        if (v[i].first < 0)
        {
            d = min(d, v[i].first);
        }
        if (v[i].second < 0)
        {
            c = min(c, v[i].second);
        }
    }
    if (c == 101)
    {
        c = 0;
    }
    if (d == 101)
    {
        d = 0;
    }
    cout << ((a * 2) + (b * 2) + abs(c * 2) + abs(d * 2)) << el;
}