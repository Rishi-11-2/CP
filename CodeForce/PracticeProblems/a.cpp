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
    int n;
    cin >> n;
    int l, r;
    cin >> l >> r;
    if (n == 1)
    {
        cout << "YES" << el;
        cout << l << el;
        return;
    }
    int arr[n];
    for (int i = 1; i < n + 1; i++)
    {
        int k = ((l / i) * i);
        arr[i - 1] = k;
        if (k < l)
        {
            arr[i - 1] += i;
            k += i;
        }
        if (k > r)
        {
            cout << "NO" << el;
            return;
        }
    }
    cout << "YES" << el;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << el;
}