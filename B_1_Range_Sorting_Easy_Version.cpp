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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    map<pair<int, int>, int> minm;
    map<pair<int, int>, int> maxm;
    for (int i = 0; i < n; i++)
    {
        minm[{i, i}] = arr[i];
        maxm[{i, i}] = arr[i];
    }

    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            if (gap == 1)
            {
                // cout << i << " " << j << endl;
                if (arr[i] > arr[j])
                    dp[i][j] = 1;
                maxm[{i, j}] = max(arr[i], arr[j]);
                minm[{i, j}] = min(arr[i], arr[j]);
            }
            else
            {
                if ((arr[i] > arr[j]) || ((arr[i] > minm[{i + 1, j - 1}]) && (arr[j] < maxm[{i + 1, j - 1}])))
                {
                    dp[i][j] = j - i;
                }
                else if ((arr[i] > minm[{i + 1, j - 1}]))
                {
                    // cout << i << " " << j << endl;
                    auto it = lower_bound(arr + i + 1, arr + (j - i), arr[i]) - arr;
                    cout << it << endl;
                    if (it == j)
                    {
                        dp[i][j] = j - i - 1;
                    }
                    else
                    {
                        dp[i][j] = it - i;
                    }
                }
                else if ((arr[j] < maxm[{i + 1, j - 1}]))
                {
                    auto it = lower_bound(arr + i + 1, arr + (j - i), arr[j]) - arr;
                    cout << it << endl;
                    if (it == i + 1 && arr[it] > arr[j])
                    {
                        dp[i][j] = j - i - 1;
                    }
                    else
                    {
                        dp[i][j] = j - it;
                    }
                }
                else
                    dp[i][j] = dp[i + 1][j - 1];
                maxm[{i, j}] = max(maxm[{i + 1, j - 1}], max(arr[i], arr[j]));
                minm[{i, j}] = min(minm[{i + 1, j - 1}], min(arr[i], arr[j]));
            }
        }
    }
    long long s = 0;
    cout << dp[8][11] << endl;
    for (auto it : dp)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    for (auto it : dp)
    {
        for (auto i : it)
            s += i * 1LL;
    }
    cout << s << endl;
}