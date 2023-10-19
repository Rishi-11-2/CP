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
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    int maxm = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        maxm = max(maxm, x * y);
    }
    function<int(int)> check = [&](int mid) -> int
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i].first <= mid)
            {
                int y = mid - v[i].first;
                if (y + mid > (v[i].second + v[i].first) - 1)
                    return 0;
            }
        }
        return 1;
    };
    int low = 1;
    int high = maxm;
    int res = 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid))
        {
            low = mid + 1;
            res = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << res << endl;
}