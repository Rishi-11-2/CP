// https://codeforces.com/contest/1707/problem/A
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
    ll n, q;
    cin >> n >> q;
    ll a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll b[n + 1];
    int nq = 0;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] <= nq)
            b[i] = 1;
        else if (nq < q)
            nq++, b[i] = 1;
        else
            b[i] = 0;
    }
    for (int i = 1; i <= n; i++)
        cout << b[i];
    cout << el;
}