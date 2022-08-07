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
bool equal(int b[], int c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (b[i] != c[i])
            return false;
    }
    return true;
}
bool divg(int c[], int n)
{
    int x = 0;
    for (int i = 2; i <= 9; i++)
    {
        x = 0;
        for (int j = 0; j < n; j++)
        {
            if (c[i] % i)
                x = 1;
        }
    }
    if (x == 1)
        return false;
    else
        return true;
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int c[n];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = (((a[i] % 10) * 2) % 10);
        c[i] = b[i];
        if (b[i] == 0)
            k++;
    }
    if (k == n)
    {
        cout << "NO" << el;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        c[i] = (c[i] * 2) % 10;
    }
    while (!equal(b, c, n))
    {
        for (int i = 0; i < n; i++)
        {
            c[i] = (c[i] * 2) % 10;
        }
        if (divg(c, n))
        {
            cout << "YES" << el;
            return;
        }
    }
    cout << "NO" << el;
}