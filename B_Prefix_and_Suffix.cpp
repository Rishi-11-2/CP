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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string z;
    cin >> z;
    if (n > m)
    {
        cout << 3 << endl;
        return;
    }
    int flag1 = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != z[i])
        {
            flag1 = 0;
        }
    }
    int flag2 = 1;
    int i = m - 1;
    int j = n - 1;
    while (j >= 0)
    {
        if (s[j] != z[i])
            flag2 = 0;
        j--;
        i--;
    }
    if (flag1 && flag2)
        cout << 0 << endl;
    else if (flag1)
    {
        cout << 1 << endl;
    }
    else if (flag2)
    {
        cout << 2 << endl;
    }
    else
        cout << 3 << endl;
}