// https://www.codechef.com/problems/SIMPLE_XOR?tab=statement
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
    ll l, r;
    cin >> l >> r;

    if (l % 2 == 0)
        cout << l << ' ' << l + 1 << ' ' << l + 2 << ' ' << l + 3 << '\n';
    else if (r == l + 3)
        cout << -1 << el;
    else
        cout << l + 1 << ' ' << l + 2 << ' ' << l + 3 << ' ' << l + 4 << '\n';
}