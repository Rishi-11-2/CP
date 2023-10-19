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
    long long n, k;
    cin >> n >> k;
    if ((n % 2 != 0) && (k % 2 == 0))
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}