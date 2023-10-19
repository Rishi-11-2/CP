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
    string s;
    cin >> s;
    int l = -1;
    int y = 0;
    int x = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (s[i] != s[i + 1])
        {
            x++;
        }
        else
        {
            if (l != s[i])
            {
                y++;
                l = s[i];
            }
        }
    }
    cout << x << " " << max(y, 1) << endl;
}