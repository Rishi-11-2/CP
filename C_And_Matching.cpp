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
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = i;

    vector<pair<int, int>> res;
    if (k == n - 1 && n == 4)
    {
        cout << -1 << endl;
        return;
    }
    if (k == 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            res.push_back({i, n - i - 1});
        }
    }
    else if (k == n - 1)
    {
        res.push_back({n - 1, n - 2});
        res.push_back({1, 3});
        res.push_back({0, (n - 1) ^ 3});
        arr[n - 1] = -1;
        arr[n - 2] = -1;
        arr[1] = -1;
        arr[3] = -1;
        arr[0] = -1;
        arr[(n - 1) ^ 3] = -1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == -1)
                continue;
            res.push_back({i, (n - 1) ^ i});
            arr[i] = -1;
            arr[(n - 1) ^ i] = -1;
        }
    }
    else
    {
        res.push_back({k, n - 1});
        res.push_back({(n - 1) ^ k, 0});
        arr[k] = -1;
        arr[n - 1] = -1;
        arr[(n - 1) ^ k] = -1;
        arr[0] = -1;
        for (int i = 1; i < n / 2; i++)
        {
            if (arr[i] == -1)
                continue;
            res.push_back({i, (n - 1) ^ i});
            arr[i] = -1;
            arr[(n - 1) ^ i] = -1;
        }
    }
    for (auto it : res)
    {
        cout << it.first << " " << it.second << endl;
    }
}