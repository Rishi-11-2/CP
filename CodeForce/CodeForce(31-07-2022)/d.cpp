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
    if (n % 10 == n)
    {
        cout << n << el;
        return;
    }
    int l = 8;
    int s = 9;
    string k = "9";
    while (l > 0)
    {
        s += l;
        k = to_string(l) + k;
        if (s == n)
            break;
        while (s > n)
        {
            s -= l;
            k = k.substr(1);
        }
        l -= 1;
        }
    cout << k << el;
}