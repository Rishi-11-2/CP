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
bool compare(vector<int> &a, vector<int> &b)
{
    return a[0] > b[0];
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    set<int> s;
    map<set<int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i].push_back(x);
        set<int> xx;
        for (int j = 0; j < x; j++)
        {
            int y;
            cin >> y;
            v[i].push_back(y);
            xx.insert(y);
            s.insert(y);
        }
        mp[xx] = 1;
    }
    sort(all(v), compare);
    for (auto it : s)
        cout << it << " ";
    cout << endl;
    int z = (int)(mp.size());
    if (z == 1 || n == 1)
    {
        cout << 0 << endl;
        return;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        set<int> s1;
        int x = v[i][0];
        for (int j = 1; j <= x; j++)
        {
            s1.insert(v[i][j]);
        }

        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            int count = (int)(s1.size());
            set<int> s2 = s1;
            // for (auto it : s2)
            //     cout << it << " ";
            // cout << endl;
            for (int k = 1; k <= v[j][0]; k++)
            {
                s1.insert(v[j][k]);
            }
            if (s1 == s && s2 != s)
            {
                res = max(res, count);
                s1 = s2;
            }
            else if (s2 != s && !s1.empty())
            {
                // cout << "hi" << endl;
                res = max(res, (int)(s1.size()));
            }
        }
    }
    cout << res << endl;
}