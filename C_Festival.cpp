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
    solve();
}
void solve()
{
    int n, m;
    cin >> n >> m;
    set<int> s;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        if (s.find(i) != s.end())
        {
            res.push_back(0);
        }
        else
        {
            auto it = s.lower_bound(i);
            res.push_back(*it - i);
        }
    }
    for (auto it : res)
        cout << it << endl;
}