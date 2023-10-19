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
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1)
    {
        cout << "YES" << endl;
        return;
    }
    if (n <= m)
    {
        cout << "NO" << endl;
        return;
    }
    int xx = sqrt(n);
    for (int i = 2; i <= min(xx, m); i++)
    {
        if (n % i == 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}