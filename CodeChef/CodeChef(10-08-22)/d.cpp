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
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    int k = n;
    int v[n];
    if (n % 2 != 0)
    {
        int z = 0;
        for (int i = 0; i < n / 2; i += 1)
        {
            if (z % 2 == 0)
            {
                swap(a[i], a[n - i - 2]);
            }
            z++;
        }
    }
    else
    {
        int z = 0;
        for (int i = 0; i < n / 2; i += 1)
        {
            if (z % 2 == 0)
            {
                swap(a[i], a[n - i - 1]);
            }
            z++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << el;
}