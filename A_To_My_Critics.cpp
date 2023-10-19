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
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b >= 10 || b + c >= 10 || a + c >= 10)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}