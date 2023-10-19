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
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int flag = -1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    vector<vector<int>> v(2);
    for (int i = 0; i < n; i++)
    {
        v[b[i]].push_back(a[i]);
    }
    int j = 0;
    for (auto &it : v)
    {
        int m = it.size();
        if (m == 0)
            j = 1;
    }
    for (auto &it : v)
    {
        int m = it.size();
        // for (auto &i : it)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        for (int i = 1; i < m; i++)
        {
            if (it[i] < it[i - 1])
            {
                if (j == 1)
                {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << endl;
}