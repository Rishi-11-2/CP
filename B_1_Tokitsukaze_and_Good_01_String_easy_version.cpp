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
    string z = s;
    char prev = s[n - 1];
    int c = 1;
    int res = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == prev)
        {
            c++;
        }
        else if (s[i] != prev)
        {
            if (c % 2)
            {
                res++;
                c++;
            }
            else
            {
                c = 1;
                prev = s[i];
            }
        }
    }
    cout << res << endl;
}