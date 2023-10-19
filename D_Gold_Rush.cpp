#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int flag = 0;
void w(int x, int m)
{
    // cout << x << endl;
    if (flag == 1)
        return;
    if (x == m)
    {
        cout << "YES" << endl;
        flag = 1;
        return;
    }
    if (x % 3 != 0)
        return;

    int y = x / 3;
    w(y, m);
    w(2 * y, m);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        flag = 0;
        solve();
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == m)
    {
        cout << "YES" << endl;
        return;
    }
    if (m > n || n % 3 != 0)
    {
        cout << "NO" << endl;
        return;
    }

    int x = n;
    w(x, m);
    if (flag == 0)
        cout << "NO" << endl;
}