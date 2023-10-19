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
    string s;
    cin >> s;
    int n = s.length();
    int m;
    cin >> m;
    string l, r;
    cin >> l >> r;
    int idx = -1;
    for (int i = 0; i < m; i++)
    {
        int mx = 0;
        vector<int> rec(10, 0);
        for (int c = l[i] - '0'; c <= r[i] - '0'; c++)
        {
            // cout << c << endl;
            rec[c] = 1;
        }
        for (int j = idx + 1; j < n; j++)
        {
            if (rec[s[j] - '0'] == 1)
            {
                mx = max(mx, j);
                rec[s[j] - '0'] = 0;
            }
        }
        // cout << idx << endl;
        idx = mx;
        for (int c = l[i] - '0'; c <= (r[i] - '0'); c++)
        {
            if (rec[c])
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}