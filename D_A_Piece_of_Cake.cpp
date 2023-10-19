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
    long long w, h;
    cin >> w >> h;
    long long m;
    cin >> m;
    long long p[m];
    long long q[m];
    for (int i = 0; i < m; i++)
    {
        cin >> p[i] >> q[i];
    }
    long long n1;
    cin >> n1;
    long long a[n1 + 1];
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }
    a[n1] = w;
    long long n2;
    cin >> n2;
    long long b[n2 + 1];
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }
    b[n2] = h;
    map<pair<long long, long long>, int> mp;
    // sort(a, a + n1 + 1);
    // sort(b, b + n2 + 1);
    for (int i = 0; i < m; i++)
    {
        long long x = *lower_bound(a, a + n1 + 1, p[i]);
        long long y = *lower_bound(b, b + n2 + 1, q[i]);
        mp[{x, y}]++;
    }
    int minm = INT_MAX;
    if (mp.size() == ((n1 + 1) * (n2 + 1)))
    {
        for (auto it : mp)
            minm = min(minm, it.second);
    }
    else
        minm = 0;
    int maxm = 0;
    for (auto it : mp)
    {
        maxm = max(maxm, it.second);
    }
    cout << minm << " " << maxm << endl;
}