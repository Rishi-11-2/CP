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
    int a[n];
    int b[n];
    vector<pair<int, int>> v;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back({a[i], i});
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        s.insert(b[i]);
    }
    // for (auto &it : s)
    //     cout << it << " ";
    // cout << endl;
    vector<int> res(n, 0);
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound(v[i].first - k);
        auto it1 = s.lower_bound(v[i].first + k);
        if (it != s.end())
        {
            res[v[i].second] = *it;
            s.erase(it);
        }
        else if (it1 != s.end())
        {
            res[v[i].second] = *it;
            s.erase(it1);
        }
    }
    for (auto &it : res)
        cout << it << " ";
    cout << endl;
}