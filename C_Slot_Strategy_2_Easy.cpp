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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int m;
    cin >> m;
    string s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    map<int, vector<int>> mp;
    for (int i = 0; i < m; i++)
    {
        int x = (s1[i] - '0');
        int y = (s2[i] - '0');
        int z = (s3[i] - '0');
        mp[x].push_back(i);
        mp[y].push_back(i);
        mp[z].push_back(i);
    }
    for (int i = 0; i <= 9; i++)
    {
        sort(mp[i].begin(), mp[i].end());
    }
}