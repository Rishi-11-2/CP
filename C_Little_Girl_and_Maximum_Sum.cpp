#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    long long t;

    solve();
}
void solve()
{
    long long n, q;
    cin >> n >> q;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    vector<long long> prefix(n + 1, 0LL);
    sort(arr, arr + n);
    reverse(arr, arr + n);
    for (long long i = 1; i <= q; i++)
    {
        long long x, y;
        cin >> x >> y;
        prefix[x]++;
        if (y < n)
            prefix[y + 1]--;
    }
    for (long long i = 1; i <= n; i++)
    {
        prefix[i] += prefix[i - 1];
    }
    vector<pair<long long, long long>> x;
    for (long long i = 1; i <= n; i++)
    {
        x.push_back({prefix[i], i});
    }
    sort(all(x), greater<pair<long long, long long>>());
    // for (auto it : x)
    //     cout << it.first << " " << it.second << endl;
    long long s = 0LL;
    for (long long i = 0; i < n; i++)
    {
        s += (arr[i] * x[i].first) * 1LL;
    }
    cout << s << endl;
}