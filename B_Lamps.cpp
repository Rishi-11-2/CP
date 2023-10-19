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
    vector<vector<int>> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }
    long long s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v.size() != 0)
        {
            sort(v[i].begin(), v[i].end());
            reverse(v[i].begin(), v[i].end());
            int sz = v[i].size();
            for (int k = 1; k <= min(i, sz); k++)
            {
                s += v[i][k - 1];
            }
        }
    }
    cout << s << endl;
}