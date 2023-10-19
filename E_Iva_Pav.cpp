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
    int n;
    cin >> n;
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<vector<int>> prefix(n + 1, vector<int>(32, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k <= 31; k++)
        {
            prefix[i][k] = prefix[i - 1][k];
            if (arr[i] & (1 << k))
            {
                prefix[i][k] = 1 + prefix[i][k];
            }
            // cout << prefix[i][k] << " ";
        }
        // cout << endl;
    }
    function<int(int, int, int)> f = [&](int mid, int l, int k) -> int
    {
        int xx = 0;
        // cout << mid << " " << l << endl;
        if (mid == l)
        {
            if (arr[mid] >= k)
                return 1;
            else
                return 0;
        }
        vector<int> y(32, 0);
        for (int i = 0; i < 32; i++)
        {
            y[i] = prefix[l][i] - prefix[l - 1][i];
        }
        for (int i = 0; i < 32; i++)
        {
            int x = prefix[mid][i] - prefix[l][i];
            if (x == (mid - l) && y[i] != 0)
            {
                // cout << i << endl;
                xx = xx + (1 << i);
            }
        }
        // cout << xx << endl;
        if (xx >= k)
            return 1;
        else
            return 0;
    };
    int q;
    cin >> q;
    vector<int> res;
    for (int i = 1; i <= q; i++)
    {
        int l, k;
        cin >> l >> k;
        int low = l;
        int high = n;
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (f(mid, l, k))
            {
                // cout << mid << endl;
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        res.push_back(ans);
    }
    for (auto it : res)
        cout << it << " ";
    cout << endl;
}