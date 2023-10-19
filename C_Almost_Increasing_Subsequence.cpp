#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int ceilIdx(int tail[], int l, int r, int x)
{
    while (r > l)
    {
        int m = l + (r - l) / 2;
        if (tail[m] >= x)
            r = m;
        else
            l = m + 1;
    }
    return r;
}
vector<int> LIS(int arr[], int x, int y)
{
    int n = (y - x + 1);
    vector<int> dp(n + 1, 0);
    int tail[n];
    int len = 1;
    int c1 = 0;
    tail[0] = arr[x - 1];
    for (int i = 1; i < n; i++)
    {
        dp[i] = len;
        if (arr[i + x - 1] > tail[len - 1])
        {
            tail[len] = arr[i + x - 1];
            len++;
            c1 = 0;
        }
        else if (c1 == 0 && arr[i + x - 1] <= tail[len - 1])
        {
            tail[len] = arr[i + x - 1];
            len++;
            c1++;
        }
        else
        {
            int c = ceilIdx(tail, 0, len - 1, arr[i + x - 1]);
            tail[c] = arr[i];
            c1 = 0;
        }
    }
    // for (auto it : tail)
    //     cout << it << " ";
    // cout << endl;
    dp[n] = len;
    return dp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
void solve()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> v;
    v = LIS(arr, 1, n);
    v[0] = 0;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
        {
            cout << 1 << endl;
            continue;
        }
        int ans = v[y] - v[x - 1];
        if (v[x] == v[x + 1])
            ans++;
        else if (v[x] == v[x - 1])
            ans++;
        cout << ans << endl;
    }
    // for (auto &it : v)
    //     cout << it << " ";
    // cout << endl;
}