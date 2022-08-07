// https://codeforces.com/contest/1707/problem/B
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
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cntZ = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        vector<int> b;
        sort(a.begin(), a.end());
        if (cntZ > 0)
        {
            b.pb(a[0]);
            cntZ--;
        }
        for (int j = 1; j < (int)(a.size()); j++)
        {
            if (a[j] == a[j - 1])
                cntZ++;
            else
                b.pb(a[j] - a[j - 1]);
        }
        a = b;
    }
    if (cntZ)
    {
        cout << 0 << el;
    }
    else
    {
        cout << a[0] << el;
    }
}