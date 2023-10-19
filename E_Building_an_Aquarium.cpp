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
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n, x;
    cin >> n >> x;
    long long arr[n];
    long long maxm = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxm = max(maxm, arr[i]);
    }
    function<long long(long long)> f = [&](long long mid) -> long long
    {
        long long count = 0;
        for (long long i = 0; i < n; i++)
        {
            count += max(0LL, mid - arr[i]);
        }
        if (count <= x)
            return 1;
        else
            return 0;
    };
    long long low = 1;
    long long high = (long long)(1e10);
    long long res = 0;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (f(mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << res << endl;
}