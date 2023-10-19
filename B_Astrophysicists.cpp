#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
bool isCheck(long long n, long long k, long long g, long long mid)
{
    // cout << mid << endl;
    long long r = (g / 2) * 1LL - 1 * 1LL;
    if (g % 2)
        r++;
    long long xx = mid;
    mid = k * g - mid;
    long long sum = k * g - (n - 1) * (r);
    if (sum < 0)
        return false;
    long long z = sum % g;
    long long h = g / 2;
    if (g % 2)
        h++;
    long long ts = 0;
    if (z >= h)
        ts = sum - z + g;
    else
        ts = sum - z;
    long long count = sum - ts + (n - 1) * r;
    // cout << xx << "  " << count << endl;
    if (xx <= count)
        return true;
    else
        return false;
}
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
    long long n, k, g;
    cin >> n >> k >> g;
    long long low = 0;
    long long high = k * g;
    long long res = high;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (isCheck(n, k, g, mid) == true)
        {
            // cout << res << endl;
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << res << endl;
}