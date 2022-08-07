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
    int next_n = floor(sqrt(n)) + 1;
    next_n *= next_n;

    int a = next_n - (n - 1);
    int arr[n];
    for (int i = a; i < n; i++)
    {
        arr[i] = next_n - i;
    }
    int b = a - 1;

    for (int i = 0; i <= b; i++)
    {
        arr[i] = b - i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << el;
}