#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
bool cmp(const pair<int, int> &a,
         const pair<int, int> &b)
{
    if (a.first != b.first)
        return (a.first > b.first);
    else
        return (a.second < b.second);
}
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
    long long n, m, h;
    cin >> n >> m >> h;
    vector<vector<long long>> v(n, vector<long long>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<pair<long long, long long>> v1;
    map<pair<long long, long long>, long long> mp;
    for (int i = 0; i < n; i++)
    {
        auto it = v[i];
        sort(all(it));
        long long s = 0;
        long long c = 0;
        long long j = 0;
        long long l = 0;
        while (j < m && l <= h)
        {
            // long long x = s + v[i][j];
            l += it[j];
            if (l > h)
            {
                break;
            }
            s = s + l;
            c++;
            j++;
        }
        v1.push_back({c, s});
        if (i == 0)
            mp[{c, s}] = 1;
    }

    // for (auto it : v1)
    //     cout << it.first << " " << it.second << " ";
    // cout << endl;
    sort(all(v1), cmp);
    for (int i = 0; i < n; i++)
    {
        if (mp[v1[i]] == 1)
        {
            cout << i + 1 << endl;
            return;
        }
    }
}