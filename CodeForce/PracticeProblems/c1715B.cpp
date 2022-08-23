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
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    if (n == 1)
    {
        if (s == (b * k))
        {
            cout << s << el;
            return;
        }
        else
        {
            cout << -1 << el;
            return;
        }
    }
    else
    {
        vector<ll> v;
        ll a = s - (b * k);
        ll s1 = (n) * (k - 1);
        if (a < 0 || a > s1)
        {
            cout << -1 << el;
            return;
        }
        else
        {
            v.pb(b * k);
            if (a > (k - 1))
            {
                v[0] += (k - 1);
                a -= (k - 1);
            }
            else
            {
                v[0] += a;
                a = 0;
            }
            int t = 1;
            while (a > 0)
            {
                if (a > (k - 1))
                    v.pb(k - 1);
                else
                    v.pb(a);
                a = a - (k - 1);
                t++;
            }
            while (t < n)
            {
                v.pb(0);
                t++;
            }
        }
        for (auto it : v)
            cout << it << " ";
        cout << el;
    }
}