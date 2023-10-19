#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
void solve()
{
    long long n, k;
    cin >> n >> k;
    long long a[n], b[n];
    long long s = 0;
    vector<pair<long long, long long>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        s += b[i];
        v.push_back({a[i], b[i]});
    }
    sort(all(v));
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s <= k)
        {
            cout << res + 1 << endl;
            return;
        }
        s -= v[i].second;
        res = v[i].first;
    }
    cout << res + 1 << endl;
}