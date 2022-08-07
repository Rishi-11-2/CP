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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int c0 = 0;
    int c1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            c0++;
        if (s[i] == '1')
            c1++;
    }
    int ans = max(c0, c1) - min(c0, c1);
    int p = 0;
    if (ans % k)
        p += 1;
    ans /= k;
    ans += p;
    cout << ans << el;
}