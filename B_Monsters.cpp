#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
bool sortC(pair<int, int> a,
           pair<int, int> b)
{
    if (a.first == b.first)
        return (a.second < b.second);
    return a.first > b.first;
}

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
        cin >> arr[i];
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i] % k;
        if (x == 0)
            res.push_back(i + 1);
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i] % k;
        if (x != 0)
        {
            // cout << x << endl;
            v.push_back({x, i + 1});
        }
    }
    sort(all(v), sortC);
    for (auto it : v)
    {
        // cout << it.first << " ";
        res.push_back(it.second);
    }
    for (auto it : res)
        cout << it << " ";
    cout << endl;
}