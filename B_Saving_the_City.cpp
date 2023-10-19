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
    string s;
    cin >> s;
    int co = 0;
    int n = s.length();
    int fo = -1;
    int lo = -1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            fo = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            lo = i;
            break;
        }
    }
    int seg = 0;
    if (fo != -1 && lo != -1)
        seg++;
    for (int i = fo; i <= lo; i++)
    {
        if (s[i] == '0')
        {
            co++;
        }
        if (s[i] == '1')
        {
            if (co > 0)
            {
                if (b * co < a)
                    res += b * co;
                else
                    seg++;
                co = 0;
            }
        }
    }
    res += seg * a;
    cout << res << endl;
}