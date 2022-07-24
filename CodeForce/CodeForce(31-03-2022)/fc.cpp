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
    if (n == 1)
    {
        cout << 1 << el;
    }
    else
    {
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = i + 1;
        }
        if (n % 2 == 0)
        {
            for (int i = 1; i < n; i += 2)
            {
                b[i - 1] = a[i];
                b[i] = a[i - 1];
            }
        }
        else
        {
            b[0] = a[n - 1];
            for (int i = 1; i < n; i++)
            {
                b[i] = a[i - 1];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << el;
    }
}