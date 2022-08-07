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
    string t;
    cin >> t;
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int z = 0;
    vector<pair<int, int>> v(1000);
    for (int i = 0; i < n; i++)
    {
        string s = arr[i];
        int l = s.length();
        int p = 0;
        int g = 0;
        while (p < t.length())
        {
            if (t.substr(p, p + l) == s)
            {
                v[z].first = p + 1;
                v[z].second = p + l;
                z++;
                g++;
                p = p + l;
            }
            else
            {
                p += 1;
            }
        }
        if (g == n / l)
            break;
    }
    if (z == 0)
    {
        cout << -1 << el;
        return;
    }
    cout << z << el;
    for (int i = 0; i < z; i++)
    {
        cout << v[i].first << " " << v[i].second << el;
    }
}
