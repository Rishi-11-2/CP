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
    int n;
    cin >> n;
    for (int k = 2; k <= n; k++)
    {
        long long x = k * (k + 1) + 1;
        if (x > n)
            break;
        long long y = k * k;
        while (x <= n)
        {
            if (x == n)
            {
                cout << "YES" << endl;
                return;
            }
            y = y * k;
            x += y;
        }
    }
    cout << "NO" << endl;
}