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
    ll n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << n - 1 << el;
        return;
    }
    if (n <= 2)
    {
        cout << 1 << el;
        return;
    }
    ll s = n - 2;
    ll count = 2;
    count += (log2(n - 2) / log2(k));
    s -= pow((log2(n - 2) / log2(k)), k);
    if (s != 0)
        count++;
    cout << count << el;
}