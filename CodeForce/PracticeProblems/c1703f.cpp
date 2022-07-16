// https://codeforces.com/contest/1703/problem/F
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int h = 1;
        ll arr[n + 1];
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] >= i)
            {
                continue;
            }
            ans += (ll)(lower_bound(v.begin(), v.end(), arr[i]) - v.begin());
            v.pb(i);
        }
        cout << ans << el;
    }
}