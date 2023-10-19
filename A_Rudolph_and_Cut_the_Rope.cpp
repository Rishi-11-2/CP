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
    int n;
    cin >> n;
    int minm = INT_MAX;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        minm = min(minm, a[i] + b[i]);
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - b[i] > 0)
            c++;
    }
    cout << c << endl;
}