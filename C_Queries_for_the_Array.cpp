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
    string s;
    cin >> s;
    int n = s.length();
    int count = 0;
    int minNSP = 0;
    int maxSP = 0;
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+')
        {
            count++;
        }
        else if (s[i] == '-')
        {
            count--;
            maxSP = min(maxSP, count);
            if (minNSP > count)
            {
                minNSP = 0;
            }
        }
        else if (s[i] == '1')
        {
            maxSP = max(maxSP, count);
        }
        else if (s[i] == '0')
        {
            if (count <= 1)
            {
                ans = false;
                break;
            }
            if (minNSP == 0 || minNSP > count)
                minNSP = count;
        }
        if (minNSP != 0 && minNSP <= maxSP)
        {
            ans = false;
            break;
        }
    }
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}