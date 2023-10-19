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
    vector<vector<long long>> v;
    for (int i = 1; i <= 3; i++)
    {
        long long x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    // for (auto it : v)
    //     cout << it[0] << " " << it[1] << endl;
    long long res = 1;
    if ((v[1][0] >= v[0][0] && v[2][0] >= v[0][0]))
    {
        res += abs(min(v[1][0], v[2][0]) - v[0][0]);
    }
    else if ((v[1][0] <= v[0][0] && v[2][0] <= v[0][0]))
    {
        res += abs(max(v[1][0], v[2][0]) - v[0][0]);
    }
    if ((v[1][1] >= v[0][1] && v[2][1] >= v[0][1]))
    {
        res += abs(min(v[1][1], v[2][1]) - v[0][1]);
    }
    else if ((v[1][1] <= v[0][1] && v[2][1] <= v[0][1]))
    {
        res += abs(max(v[1][1], v[2][1]) - v[0][1]);
    }
    cout << res << endl;
}