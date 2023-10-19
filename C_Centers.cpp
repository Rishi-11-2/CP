#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= 3 * n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<vector<int>> x(n + 1);
    for (int i = 1; i <= 3 * n; i++)
    {
        x[v[i - 1]].push_back(i);
    }
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; i++)
    {
        auto z = x[i];
        // cout << z[1] << endl;
        a.push_back({z[1], i});
    }
    sort(all(a));
    for (auto it : a)
    {
        cout << it.second << " ";
    }
    cout << endl;
}