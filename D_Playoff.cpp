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
    solve();
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = 1 << n;
    int st = 0;
    int en = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            st++;
        if (s[i] == '0')
            en++;
    }
    int ss = 1 + (1 << st) - 1;
    int ee = (m - (1 << en)) + 1;
    for (int i = ss; i <= ee; i++)
        cout << i << " ";
    cout << endl;
}