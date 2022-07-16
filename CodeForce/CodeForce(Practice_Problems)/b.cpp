#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define ht unordered_map
#define uset unordered_set
#define ll long long int
#define lld long double
int main()
{

    ll n, q;
    cin >> n >> q;
    ll a[n];
    ll p[n + 1] = {0};
    p[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i] + a[i - 1];
    }
    for (int i = 1; i < n + 1; i++)
    {
        p[i] = a[i - 1];
    }
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        cout << p[x] - p[x - y] << el;
    }
}