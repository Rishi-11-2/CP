#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
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
    long long a[n];
    long long b[n];
    vector<vector<long long>> v(n + 1);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    for (long long i = 0; i < n; i++)
    {
        cin >> b[i];
        v[a[i]].push_back(b[i]);
    }
    vector<long long> res(n + 1, 0);
    vector<vector<long long>> pref;
    long long maxm = 0;
    vector<vector<long long>> z;
    for (long long i = 1; i <= n; i++)
    {
        if (v[i].size() == 0)
            continue;
        long long m = v[i].size();
        maxm = max(maxm, m);
        sort(all(v[i]), greater<long long>());
        z.push_back(v[i]);
    }
    for (auto &it : z)
    {
        long long m = it.size();
        vector<long long> prefix(m, 0);
        prefix[0] = it[0];
        for (long long j = 1; j < m; j++)
            prefix[j] = prefix[j - 1] + it[j];
        pref.push_back(prefix);
    }
    for (auto it : pref)
    {
        for (long long k = it.size(); k >= 1; k--)
        {
            long long idx = (it.size()) / k;
            idx = idx * k;
            res[k] += it[idx - 1];
        }
    }

    for (long long i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;
}