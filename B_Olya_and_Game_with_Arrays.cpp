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
    long long n;
    cin >> n;
    vector<long long> v1;
    vector<long long> v2;
    for (long long i = 1LL; i <= n; i++)
    {
        long long m;
        cin >> m;
        vector<long long> b;
        for (long long j = 0LL; j < m; j++)
        {
            long long x;
            cin >> x;
            b.push_back(x);
        }
        sort(all(b));
        v1.push_back(b[0]);
        v2.push_back(b[1]);
    }
    long long s = 0LL;
    for (auto it : v1)
        s += it;
    long long s1 = 0LL;
    for (auto it : v2)
        s1 += it;
    sort(all(v1));
    sort(all(v2));
    s1 = s1 + v1[0] - v2[0];
    cout << max(s1, s) << endl;
}