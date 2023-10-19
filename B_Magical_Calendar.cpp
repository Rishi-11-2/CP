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
    long long n, k;
    cin >> n >> k;
    if (n <= k)
    {
        long long y = n - 1;
        long long x = y * (y + 1);
        x /= 2;
        cout << x + 1 << endl;
    }
    else
    {
        long long x = k * (k + 1);
        x /= 2;
        cout << x << endl;
    }
}