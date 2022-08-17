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
    string s;
    cin >> s;
    int l = 0;
    int a = 0, b2 = 0, b1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            b1++;
    }
    a = 0;
    if (b1 == n)
    {
        cout << n * m << el;
        return;
    }
    a = 0;
    b1 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            l = i;
            break;
        }
        b2++;
    }
    for (int i = 0; i <= l; i++)
    {

        if (s[i] == '0')
            b1++;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            a++;
    }

    if (a % 2 == 0)
    {
        if (m % 2 != 0)
        {
            cout << b1 + 1 << el;
        }
        else
        {
            cout << b2 + 1 << el;
        }
    }
    else
    {
        cout << 0 << el;
    }
}