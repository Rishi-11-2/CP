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
    int res = 0;
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = 0;
        int maxm = 0;
        for (int j = n, k = i; j >= i; j--, k++)
        {
            x += (j * k);
            maxm = max(maxm, j * k);
        }
        res = max(res, s + x - maxm);
        s += (i * i);
    }
    cout << res << endl;
}