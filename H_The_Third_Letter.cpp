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
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    int flag = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        if (mp.find(x) == mp.end() && mp.find(y) == mp.end() && d != 0)
        {
            mp[y] = 0;
            mp[x] = d;
        }
        else if (mp.find(x) != mp.end() && mp.find(y) == mp.end() && d != 0)
        {
            mp[y] = -d + mp[x];
        }
        else if (mp.find(y) != mp.end() && mp.find(x) == mp.end() && d != 0)
        {
            mp[x] = d + mp[y];
        }
        else if (mp.find(x) != mp.end() && mp.find(y) != mp.end())
        {
            // cout << x << " " << y << endl;
            if (abs(mp[x] - mp[y]) != abs(d))
            {
                flag = 1;
            }
        }
    }
    if (!flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}