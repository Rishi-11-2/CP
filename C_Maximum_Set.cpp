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
    int mod = 998244353;
    int l, r;
    cin >> l >> r;
    int ms = 0;
    int x = l;
    while (x <= r)
    {
        x = x * 2;
        ms++;
    }
    int low = l;
    int high = r;
    int res = -1;
    ms--;
    long long a = (1LL << ms);
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if ((mid * a) <= r)
        {
            // cout << res << endl;
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    low = l;
    high = r;
    int ans = 0;
    if (res != -1)
        ans += (res - l + 1) % mod;
    int res1 = -1;
    a = a / 2;
    a = a * 3;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if ((mid * a) <= r)
        {
            res1 = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    if (res1 != -1)
        ans += ((res1 - l + 1) % mod * (ms) % mod) % mod;
    cout << ms + 1 << " " << ans << endl;
}