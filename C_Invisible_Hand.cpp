#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
void solve()
{
    long long n, m;
    cin >> n >> m;
    long long a[n];
    long long b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    sort(a, a + n);
    sort(b, b + m);
    long long minm = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        long long x = lower_bound(b, b + m, a[i]) - b;
        if ((i + 1) >= (m - x))
        {
            minm = a[i];
            break;
        }
    }
    long long maxm = 0;
    for (long long i = 0; i < m; i++)
    {
        long long x = upper_bound(a, a + n, b[i]) - a;
        // cout << x << endl;
        if (x >= (m - (i + 1)))
        {
            minm = min(minm, b[i] + 1);
            break;
        }
    }
    cout << minm << endl;
}