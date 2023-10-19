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
    int a[n];
    int b[n];
    int m = 1000000007;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    int c[n];
    for (int i = 0; i < n; i++)
    {
        c[i] = lower_bound(a, a + n, b[i] + 1) - a;
        c[i] = n - c[i];
    }
    reverse(c, c + n);
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        // cout << c[i] << endl;
        ans = (ans % m) * (max(0, (c[i] - i)) % m);
    }
    // for (auto &it : c)
    //     cout << it << " ";
    // cout << endl;
    cout << ans << endl;
}