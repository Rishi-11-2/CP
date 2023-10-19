#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int i = 0;
    int res = 0;
    while (i < n)
    {
        while (i < n)
        {
            if (s[i] == 'W')
                i++;
            else
                break;
        }
        if (i == n)
            break;
        int count = 0;
        res++;
        while (i < n && count < k)
        {
            count++;
            i++;
        }
    }
    cout << res << endl;
}