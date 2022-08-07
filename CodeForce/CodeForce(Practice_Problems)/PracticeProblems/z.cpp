// https://codeforces.com/contest/1716/problem/a
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
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 2 << el;
        return;
    }

    if (n % 3 == 0)
    {
        cout << n / 3 << el;
        return;
    }
    else if (n % 3 == 2)
    {
        cout << (n / 3 + 1) << el;
        return;
    }
    else
    {
        int h = min((n / 3 + 2), (n / 2));
        int g = ((n / 3) - 1) + (n - (3 * ((n / 3) - 1))) / 2;
        cout << min(g, h) << el;

        return;
    }
}