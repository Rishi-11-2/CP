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
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({a[i] - b[i], i + 1});
    }
    sort(all(v));
    int count = 1;
    int maxm = v[n - 1].first;
    vector<int> res;
    res.push_back(v[n - 1].second);
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i].first == maxm)
        {
            count++;
            res.push_back(v[i].second);
        }
        else
            break;
    }
    sort(all(res));
    cout << count << endl;
    for (auto it : res)
        cout << it << " ";
    cout << endl;
}