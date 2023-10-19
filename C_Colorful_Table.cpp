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
    int n, k;
    cin >> n >> k;
    int arr[n];
    vector<int> vis(k + 1, 0);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        vis[arr[i]] = 1;
        mp[arr[i]].push_back(i);
    }
    int sum = n * 2;
    for (int i = 1; i <= k; i++)
    {
        sort(mp[i].begin(), mp[i].end());
    }
    vector<int> res(k + 1, 0);
    int maxIdx = 0;
    int minIdx = INT_MAX;
    for (int i = k; i >= 1; i--)
    {
        if (vis[i] == 0)
            continue;
        maxIdx = max(maxIdx, mp[i].back());
        minIdx = min(minIdx, mp[i].front());
        res[i] = (maxIdx - minIdx + 1) * 2;
    }
    for (int i = 1; i <= k; i++)
        cout << res[i] << " ";
    cout << endl;
}