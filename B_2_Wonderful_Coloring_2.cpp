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
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    vector<int> v[n + 1];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
        v[x].push_back(i);
    }
    // for (auto it : mp)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }
    vector<int> ans(n + 1, 0);
    vector<pair<int, int>> vv;
    for (auto it : mp)
    {
        if (it.second >= k)
        {
            int color = 1;
            for (int i = 0; i < k; i++)
            {
                ans[v[it.first][i]] = color;
                color++;
            }
        }
        else
        {
            for (int i = 0; i < (int)(v[it.first].size()); i++)
            {
                vv.push_back({it.first, v[it.first][i]});
            }
        }
    }
    int x = vv.size() % k;
    int sz = vv.size();
    sz -= x;
    int curr = 1;
    for (int i = 0; i < sz; i++)
    {
        ans[vv[i].second] = curr;
        curr++;
        if (curr > k)
            curr = 1;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}