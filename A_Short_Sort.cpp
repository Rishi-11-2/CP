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
    string z = "abc";
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] != z[i])
            count++;
    }
    if (count > 2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}