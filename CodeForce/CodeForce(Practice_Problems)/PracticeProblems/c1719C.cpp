// https://codeforces.com/contest/1719/problem/C
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
    int n, q;
    cin >> n >> q;
    int arr[n];
    vector<int> v2;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v2.pb(arr[i]);
    }
    vector<pair<int, int>> v(q);
    ht<int, int> m;
    int maxM = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> v[i].first >> v[i].second;
        maxM = max(v[i].second, maxM);
        m[v[i].first] = 0;
    }
    int first = 0;
    int last = 1;
    for (int i = 0; i < maxM; i++)
    {

        if (v2[first] > v2[last])
        {
            m[v2[first]]++;
            v2.pb(v2[last]);
            last++;
        }
        else
        {

            m[v2[last]]++;
            v2.pb(v2[first]);
            first = last;
            last++;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << m[v[i].first] << el;
    }
    return;
}