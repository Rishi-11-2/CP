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
    ll n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    ll prev = a[0];
    ll curr = a[1];
    ll x = b[0];
    int i = 0;
    int j = 0;
    while (i < n - 1 and j < m - 1)
    {
        if (x == prev || x == curr)
        {
            curr = a[++i];
            prev = x;
            x = b[++j];
        }
        else
        {
            curr = a[++i];
        }
    }
    if (j == m - 1)
    {
        cout << "YES" << el;
    }
    else
    {
        cout << "NO" << el;
    }
}