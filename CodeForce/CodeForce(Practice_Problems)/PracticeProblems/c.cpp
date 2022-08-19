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
#define INF INT_MAX
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
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0 and c == 0)
    {
        cout << 0 << el;
    }
    else if ((a == 0 and c != 0) or (a != 0 and c == 0))
    {
        cout << 1 << el;
    }
    else
    {
        ll z1 = a * d;
        ll z2 = b * c;

        if (z1 == z2)
        {
            cout << 0 << el;
        }

        else if (z1 % z2 == 0 or z2 % z1 == 0)
        {
            cout << 1 << el;
        }
        else
        {
            cout << 2 << el;
        }
    }
}