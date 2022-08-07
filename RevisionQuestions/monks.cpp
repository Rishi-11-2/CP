// https://www.codechef.com/problems/MONKS?tab=statement
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
ll Ceil(ll a, ll b)
{
    int p = 0;
    if (a % b)
        p += 1;
    a /= b;
    a += p;
    return a;
}
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
    int n;
    cin >> n;
    ll arr[n];
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + n);
    if (arr[0] == arr[n - 1])
    {
        cout << 0 << el;
        return;
    }
    ll prefix_sum = 0;
    ll ans = n;
    for (int i = 0; i < n; i++)
    {
        ll x = arr[i];
        prefix_sum += arr[i];
        ll suffix_sum = sum - prefix_sum;
        if (suffix_sum >= arr[i] * (i + 1) - prefix_sum)
            ans = min(ans, (ll)n - (i + 1));
    }
    cout << ans << el;
}
