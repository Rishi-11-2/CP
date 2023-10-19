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
    long long n, m, d;
    cin >> n >> m >> d;
    vector<long long> a(n, 0);
    vector<long long> b(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    sort(all(a));
    sort(all(b));
    long long i = 0;
    long long j = 0;
    long long maxm = -1;
    for (int i = 0; i < n; i++)
    {
        auto y = upper_bound(all(b), a[i] + d);
        if (y != b.begin())
        {
            long long j = *(y - 1);
            if (abs(j - a[i]) <= d)
                maxm = max(a[i] + j, maxm);
        }
    }
    cout << maxm << endl;
}