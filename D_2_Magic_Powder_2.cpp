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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    function<int(long long)> check = [&](long long mid) -> int
    {
        long long x = k;
        for (int i = 0; i < n; i++)
        {
            long long c = b[i] - mid * a[i];
            if (c >= 0)
                continue;
            if (c + x < 0)
            {
                return 0;
            }
            x = x + c;
        }
        return 1;
    };
    long long low = 1;
    long long high = (long long)(1e10);
    long long res = 0;
    while (low <= high)
    {
        long long mid = (high + low) / 2;
        if (check(mid))
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