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
    vector<vector<long long>> v;
    for (int i = 1; i <= n; i++)
    {
        long long a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    map<long long, long long> f, s;
    for (auto it : v)
    {
        f[it[0]]++;
        s[it[1]]++;
    }
    map<int, int> m1;
    map<int, int> m2;
    long long res = 1;
    for (long long i = 0; i < min(3 * 1LL, n - 3); i++)
    {
        res = (res * (n - i)) * 1LL;
        res = res / (i + 1);
    }
    // cout << res << endl;
    long long c = 0;
    for (int i = 0; i < n; i++)
    {
        if (f[v[i][0]] > 1 && s[v[i][1]] > 1)
            c += (f[v[i][0]] - 1) * (s[v[i][1]] - 1) * 1LL;
    }
    cout << (res - c) << endl;
}