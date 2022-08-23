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
    ll arr[n];
    ll maxM = 0;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > maxM)
        {
            maxM = arr[i];
            index = i;
        }
    }

    vector<pair<int, int>> v(q);
    for (int i = 0; i < q; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < q; i++)
    {
        int count = 0;
        int index = v[i].first - 1;
        int index1 = lower_bound(arr, arr + n, arr[index]) - arr;
        // cout << index1 << el;
        if (index1 < index)
            count = 0;
        else
        {
            count += index;
            count += (index1 - (index + 1));
        }
        if (arr[index] == maxM)
        {
            count = (v[i].second - (index + 1) / 2);
        }
        cout << count << el;
    }
}