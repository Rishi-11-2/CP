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
    long long n, k;
    cin >> n >> k;
    long long a[n];
    long long h[n];
    long long minm = (long long)(1e16);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        minm = min(minm, a[i]);
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    if (minm > k)
    {
        cout << 0 << endl;
        return;
    }
    function<long long(long long)> f = [&](long long mid) -> long long
    {
        long long count = 1;
        long long sum = a[0];
        long long res = 1;
        for (long long i = 1; i < n; i++)
        {
            if ((sum + a[i]) > k)
            {
                res = max(res, count);
                count = 1;
                sum = a[i];
            }
            else if ((h[i - 1] % h[i]) == 0)
            {
                if (count == 0)
                    count += 2;
                else
                    count++;
                res = max(res, count);
                sum = sum + a[i] * 1LL;
            }
            else
            {
                res = max(res, count);
                count = 0;
                sum = a[i];
            }
        }
        if (sum <= k)
            res = max(res, count);
        if (res >= mid)
            return 1LL;
        else
            return 0LL;
    };
    long long low = 1;
    long long high = n * 2;
    long long res = 1;
    while (low <= high)
    {
        long long mid = (low + high) / 2LL;
        // cout << mid << endl;
        if (f(mid) == 1)
        {
            low = mid + 1;
            res = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << res << endl;
}