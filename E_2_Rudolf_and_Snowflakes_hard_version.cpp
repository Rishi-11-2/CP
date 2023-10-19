#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
bool isPower(long long y, long long x)
{
    if (x == 1)
        return (y == 1);

    // Repeatedly compute power of x
    long long pow = 1;
    long long c = 0;
    while (pow < y)
    {
        c++;
        pow *= x;
    }

    // Check if power of x becomes y
    return (pow == y && c > 2);
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
    long long n;
    cin >> n;
    for (long long k = 2; k <= 10000; k++)
    {
        long long x = n - 1;
        long long y = x * (k - 1);
        y = y + k * (1LL);
        if (isPower(y, k))
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
