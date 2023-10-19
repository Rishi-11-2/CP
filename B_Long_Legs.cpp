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
    int a, b;
    cin >> a >> b;
    // if (__gcd(a, b) == 1)
    // {
    int c = min(a, b);
    int d = max(a, b);
    int res = INT_MAX;  
    for (int i = 1; i <= 100000; i++)
    {
        int x = (a + i - 1) / i;
        int y = (b + i - 1) / i;
        res = min(res, x + y + i - 1);
    }
    cout << res << endl;
}