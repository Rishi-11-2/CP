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
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    long long q;
    vector<long long> res;
    cin >> q;
    for (long long i = 1; i <= q; i++)
    {
        long long x, y;
        cin >> x >> y;
        long long z = sqrt(x * x - 4LL * y);
        if ((z * z) != ((x * x) - (4LL * y)))
        {
            res.push_back(0LL);
            continue;
        }
        long long t1 = (x + z) * 1LL;
        t1 = t1 / 2LL;
        long long t2 = (x - z) * 1LL;
        t2 = t2 / 2LL;
        // cout << t1 << " " << mp[t2] << endl;
        long long count = 0LL;
        if (t1 == t2)
            count = (mp[t1] * (mp[t2] - 1)) / 2LL;
        else
            count = mp[t1] * mp[t2];
        res.push_back(count);
    }
    for (auto it : res)
        cout << it << " ";
    cout << endl;
}