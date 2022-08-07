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
    string s, r;
    cin >> s;
    cin >> r;
    bool l = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            l = !l;
        }
    }
    for (int i = 0; i < r.length(); i++)
    {
        if (r[i] == '1')
        {
            l = !l;
        }
    }
    cout << l << el;
}