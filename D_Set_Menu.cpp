#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    long long t;
    solve();
}
void solve()
{
    long long n, m, p;
    cin >> n >> m >> p;
    vector<long long> a(n, 0);
    vector<long long> b(m, 0);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    for (long long i = 0; i < m; i++)
        cin >> b[i];
    sort(all(a));
    sort(all(b));
    long long prefix[m];
    prefix[0] = b[0];
    for (long long i = 1; i < m; i++)
    {
        prefix[i] = b[i] + prefix[i - 1];
    }
    long long s = 0;
    for (long long i = 0; i < n; i++)
    {
        long long x = p - a[i];
        long long idx = lower_bound(b.begin(), b.end(), x) - b.begin();
        if (idx > 0)
        {
            s = s + prefix[idx - 1] + (idx)*a[i];
        }
        s = s + (m - (idx)) * p;
    }
    cout << s << endl;
}