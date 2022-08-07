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
    int a[2][2];
    int f = 0;
    for (int i = 0; i < 2; i++)
    {

        for (int j = 0; j < 2; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                f += 1;
        }
    }
    if (f == 4 or f == 3)
        cout << 2 << el;
    else if (f == 2 or f == 1)
        cout << 1 << el;
    else
        cout << 0 << el;
}