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
    long long n, x, p;
    cin >> n >> x >> p;
    long long y1 = n - x;
    for (long long i = 1; i <= min(2 * n, p); i++)
    {
        long long y = i * (i + 1);
        y /= 2;
        if ((y + x) % n == 0)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}