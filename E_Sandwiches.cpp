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

    solve();
}
void solve()
{
    long long n;
    cin >> n;
    long long arr[n];
    map<long long, vector<long long>> mp;
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }
    long long count = 0LL;
    for (auto it : mp)
    {
        long long sz = it.second.size();
        if (sz == 0)
            continue;
        auto v = it.second;
        vector<long long> prefix(sz, 0LL);
        for (long long i = 1; i < sz; i++)
        {
            prefix[i] = prefix[i - 1] + (v[i] - v[i - 1] - 1LL) * i;
        }
        for (long long i = 0; i < sz; i++)
            count = count * 1LL + prefix[i] * 1LL;
    }
    cout << count << endl;
}