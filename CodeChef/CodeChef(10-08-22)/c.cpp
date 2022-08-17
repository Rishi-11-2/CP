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
vector<ll> v;
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for (ll i = 0; i < 32; i++)
    {
        for (ll j = i + 1; j < 32; j++)
        {
            ll s = (1 << i) + (1 << j);
            v.pb(s);
        }
    }
    sort(v.begin(), v.end());
    while (t--)
    {
        solve();
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll>::iterator it;
    if (ceil(log2(n)) == floor(log2(n)))
    {
        cout << 0 << el;
        return;
    }
    int g = 0;
    it = find(v.begin(), v.end(), (ll)n);
    if (it != v.end())
    {
        cout << 1 << el;
        return;
    }
    while (n > 0)
    {
        int c = log2(n);
        int d = (int)pow(2, c);
        n = n - d;
        g++;
        it = find(v.begin(), v.end(), (ll)n);
        if (it != v.end())
        {
            g++;
            break;
        }
    }
    cout << g << el;
}