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
    int n;
    cin >> n;
    int b[n / 2];
    vector<pair<int, int>> y;
    for (int i = 0; i < n / 2; i++)
    {
        cin >> b[i];
        y.push_back({b[i], i});
    }
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    for (int i = 0; i < n / 2; i++)
        s.erase(b[i]);
    sort(y.begin(), y.end());
    vector<int> v(n, 0);
    int t = 0;
    for (int i = 0; i < n; i += 2)
    {
        auto x = s.begin();
        v[2 * y[t].second] = min(*x, y[t].first);
        v[2 * y[t].second + 1] = max(*x, y[t].first);
        s.erase(x);
        t++;
    }
    for (auto it : v)
        cout << it << " ";
    cout << endl;
    t = 0;
    for (int i = 0; i < n - 1; i += 2)
    {
        if (max(v[i], v[i + 1]) != b[t++])
        {
            cout << -1 << endl;
            return;
        }
    }
}