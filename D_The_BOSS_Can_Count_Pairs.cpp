#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int f[625][(int)(2e5 + 5)];
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
    int a[n], b[n];
    memset(f, 0, sizeof(f));
    int maxm = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxm = max(maxm, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 625)
        {
            f[a[i]][b[i]] += 1;
        }
    }
    int res = 0;
    // cout << maxm * maxm << endl;
    for (int i = 0; i < n; i++)
    {
        int c = 1;
        int x = a[i];
        int diff = x - b[i];
        while (diff <= n && c <= 625)
        {
            x = a[i] * c;
            // cout << a[i] << " " << x << endl;
            if (x < b[i])
            {
                // cout << "a" << endl;
                c++;
                continue;
            }
            diff = x - b[i];
            // cout << diff << " " << c << endl;
            if (diff <= n)
            {
                // cout << c << " " << diff << " " << f[c][diff] << endl;
                res += f[c][diff];
                if (c == a[i] && diff == b[i])
                    res--;
            }
            else
                break;
            c++;
        }
        // cout << endl;
    }
    cout << res / 2 << endl;
}