#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin >> n;
    long long arr[n];
    vector<pair<long long, long long>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v.push_back({arr[i], i});
    }
    sort(all(v));
    map<long long, long long> mp;
    long long s = 0;
    for (int i = 0; i < n; i++)
    {
        s += (v[i].first) - v[0].first + 1;
    }
    mp[v[0].second] = s;
    for (int i = 1; i < n; i++)
    {
        long long x = v[i].first - v[i - 1].first;
        // cout << x << endl;
        // cout << (x * (i + 1)) << " " << x * (n - (i + 1)) << endl;
        s += (x * (i));
        s -= (x * (n - (i)));
        mp[v[i].second] = s;
    }
    for (int i = 0; i < n; i++)
        cout << mp[i] << " ";
    cout << endl;
}