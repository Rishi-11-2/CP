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
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    string x = a;
    string y = b;
    sort(all(x));
    sort(all(y));
    if (x != y)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            continue;
        if (!(i + k < n || i - k >= 0))
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}