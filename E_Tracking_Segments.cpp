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
    vector<pair<int, int>> segments;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        segments.push_back({x, y});
    }
    int q;
    cin >> q;
    vector<int> c;
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        c.push_back(x);
    }
    int low = 0;
    int high = c.size() - 1;
    int res = INT_MAX;
    int flag = 0;
    while (low <= high)
    {
        flag = 0;
        int mid = (low + high) / 2;
        vector<int> pre(n + 1, 0);
        for (int i = 0; i <= mid; i++)
        {
            pre[c[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + pre[i];
        }
        for (int i = 0; i < m; i++)
        {
            int x = segments[i].first;
            int y = segments[i].second;
            int z = (y - x + 1);
            int h = z / 2;
            if (pre[y] - pre[x - 1] > (h))
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            res = min(res, mid + 1);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    if (res == INT_MAX)
        res = -1;
    cout << res << endl;
}