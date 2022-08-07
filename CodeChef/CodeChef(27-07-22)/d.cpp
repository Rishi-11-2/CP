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
    int a, b, c;
    cin >> a >> b >> c;
    int x = min(a, b);
    x = min(x, c);
    if (a == b and b == c)
    {
        cout << "YES" << el;
    }
    else if (x == c and x == a)
    {
        cout << "YES" << el;
    }
    else if (x == b and x == a)
    {
        cout << "YES" << el;
    }
    else if (x == c and x == b)
    {
        cout << "YES" << el;
    }
    else
    {
        cout << "NO" << el;
    }
}