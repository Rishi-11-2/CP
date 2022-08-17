// https://codeforces.com/contest/1617/problem/C
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
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    uset<int> u;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] <= n and u.find(arr[i]) == u.end())
            u.insert(arr[i]);
    }
    int min1 = INT_MAX;
    int max1 = arr[0];
    vector<int> v;
    for (int i = n; i >= 1; i--)
    {
        if (u.find(i) == u.end())
        {
            v.pb(i);
        }
    }
    int c = 0;
    vector<int> x;
    uset<int> v1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > n)
        {
            x.pb(arr[i]);
        }
        else
        {
            if (v1.find(arr[i]) != v1.end())
            {

                x.pb(arr[i]);
            }
        }
        v1.insert(arr[i]);
    }
    int t = (int)(v.size());
    sort(all(v));
    sort(all(x));

    c = 0;
    for (int i = 0; i < t; i++)
    {
        int h = ceil(x[i] / v[i]);
        if (x[i] % v[i] != 0)
            h++;
        if (h <= 2)
        {
            cout << -1 << el;
            return;
        }
        c++;
    }
    cout << c << el;
}
