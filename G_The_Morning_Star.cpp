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
    map<long long, long long> xc;
    map<long long, long long> yc;
    map<long long, long long> mp1;
    map<long long, long long> mp2;
    long long c = 0;
    for (long long i = 1; i <= n; i++)
    {
        long long x, y;
        cin >> x >> y;
        xc[x]++;
        yc[y]++;

        mp1[x + y]++;
        mp2[y - x]++;
    }
    long long count = 0LL;
    for (auto it : xc)
    {
        // cout << it.first << " " << it.second << endl;
        count += (it.second) * (it.second - 1) * 1LL;
    }
    for (auto it : yc)
    {
        // cout << it.first << " " << it.second << endl;

        count += (it.second) * (it.second - 1) * 1LL;
    }
    for (auto it : mp1)
    {
        // cout << it.first << " " << it.second << endl;

        count += (it.second) * (it.second - 1) * 1LL;
    }
    for (auto it : mp2)
    {
        // cout << it.first << " " << it.second << endl;

        count += (it.second) * (it.second - 1) * 1LL;
    }
    cout << count << endl;
}