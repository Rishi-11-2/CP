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
    int x, k;
    cin >> x >> k;
    if (x % k)
    {
        cout << 1 << endl;
        cout << x << endl;
    }
    else
    {
        cout << 2 << endl;
        cout << x - 1 << " " << 1 << endl;
    }
}