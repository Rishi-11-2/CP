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
    int ans = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            if (s[i] == '>' && s[i - 1] == '<')
            {
                res = max(res, ans);
                ans = 1;
            }
            else if (s[i] == '<' && s[i - 1] == '>')
            {
                res = max(res, ans);
                ans = 1;
            }
            else
                ans++;
        }
        else
            ans++;
    }
    res = max(res, ans);

    cout << res + 1 << endl;
}