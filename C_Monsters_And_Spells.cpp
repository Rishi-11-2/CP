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
    int h[n];
    int k[n];
    for (int i = 0; i < n; i++)
        cin >> k[i];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    int res = 0;
    res += (h[0] * (h[0] + 1)) / 2;
    int prev = h[0];
    for (int i = 1; i < n; i++)
    {
        int d = k[i] - k[i - 1];
        if (h[i] <= d)
        {
            res += (h[i] * (h[i] + 1)) / 2;
            prev = h[i];
        }
        else if (h[i] > d)
        {
            int t = max(h[i - 1] + d, h[i]);
            res += (t * (t + 1)) / 2 - (prev * (prev + 1)) / 2;
            prev = t;
        }
    }
    cout << res << endl;
}