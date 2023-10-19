#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
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
    int x, y, n;
    cin >> x >> y >> n;
    int d = 1;
    int a[n];
    a[n - 1] = y;
    for (int i = n - 2; i >= 1; i--)
    {
        a[i] = a[i + 1] - d;
        d++;
    }
    a[0] = x;
    int d1 = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= a[i - 1])
        {
            cout << -1 << endl;
            return;
        }
        int d2 = a[i] - a[i - 1];
        if (d2 >= d1)
        {
            cout << -1 << endl;
            return;
        }
        d1 = d2;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}