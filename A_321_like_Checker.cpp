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
    string s = to_string(n);
    int len = s.length();
    for (int i = 1; i < len; i++)
    {
        int x = s[i - 1] - '0';
        int y = s[i] - '0';
        if (x <= y)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}