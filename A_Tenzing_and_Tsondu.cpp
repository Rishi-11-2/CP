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
    long long a[n];
    long long s1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s1 += a[i] * 1LL;
    }
    long long b[m];
    long long s2 = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        s2 += b[i] * 1LL;
    }
    if (s1 > s2)
    {
        cout << "Tsondu" << endl;
    }
    else if (s2 > s1)
    {
        cout << "Tenzing" << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }
}