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
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    char c[m + 1];
    for (int i = 1; i <= m; i++)
    {
        c[i] = 'B';
    }
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        int b = (m + 1 - arr[i]);
        int x = max(a, b);
        int y = min(a, b);
        if (c[y] != 'A')
            c[y] = 'A';
        else
            c[x] = 'A';
    }
    for (int i = 1; i <= m; i++)
    {
        cout << c[i];
    }
    cout << el;
}