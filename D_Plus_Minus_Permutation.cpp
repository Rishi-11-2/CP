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
    long long n, x, y;
    cin >> n >> x >> y;
    long long g = __gcd(x, y);
    long long z = (x * y) / g;
    long long c1 = n / x;
    long long c2 = n / y;
    long long c3 = n / z;
    // cout << c1 << " " << c2 << " " << c3 << endl;
    long long c5 = c2 - c3;
    long long s2 = c5 * (c5 + 1);
    s2 = s2 / 2;
    long long c4 = c1 - c3;
    long long s1 = n * (n + 1);
    s1 = s1 / 2;
    long long s3 = (n - c4) * (n - (c4 - 1));
    s3 = s3 / 2;
    s1 = s1 - s3;
    cout << s1 - s2 << endl;
}