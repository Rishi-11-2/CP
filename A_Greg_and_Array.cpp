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
    long long n, m, k;
    cin >> n >> m >> k;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<long long>> operations;
    for (int i = 1; i <= m; i++)
    {
        int l, r, d;
        cin >> l >> r >> d;
        operations.push_back({l, r, d});
    }
    vector<vector<long long>> ranges;
    vector<long long> prefix(m + 1, 0);
    for (int i = 1; i <= k; i++)
    {
        int l, r;
        cin >> l >> r;
        ranges.push_back({l, r});
        prefix[l] += 1;
        if (r < m)
            prefix[r + 1] -= 1;
    }
    for (int i = 1; i <= m; i++)
    {
        prefix[i] += prefix[i - 1];
        // cout << prefix[i] << " ";
    }
    // cout << endl;
    vector<long long> v(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        long long l = operations[i - 1][0];
        long long r = operations[i - 1][1];
        long long d = operations[i - 1][2];
        v[l] += (d * prefix[i]);
        if (r < n)
        {
            v[r + 1] -= (d * prefix[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        v[i] += v[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] + arr[i - 1] << " ";
    }
    cout << endl;
}