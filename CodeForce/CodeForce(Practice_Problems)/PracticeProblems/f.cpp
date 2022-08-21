// https://codeforces.com/contest/1719/problem/B
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
#define INF INT_MAX
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
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n, k;
    cin >> n >> k;

    if (k % 2 == 0)
    {
        if ((k + 2) % 4 != 0)
        {
            cout << "NO" << el;
            return;
        }
    }
    vector<pair<int, int>> v(n / 2);
    int x = 1;
    int y = 2;
    for (int i = 0; i < n / 2; i++)
    {
        if (k % 2 == 0)
        {
            if (y % 4 != 0)
            {
                v[i].first = y;
                v[i].second = x;
            }
            else
            {
                v[i].first = x;
                v[i].second = y;
            }
        }
        else
        {
            v[i].first = x;
            v[i].second = y;
        }
        x += 2;
        y += 2;
    }
    cout << "YES" << el;
    for (int i = 0; i < n / 2; i++)
    {
        cout << v[i].first << " " << v[i].second << el;
    }
    return;
}