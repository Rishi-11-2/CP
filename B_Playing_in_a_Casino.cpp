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
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> v;
    // cout << n << " " << m << endl;
    for (int i = 0; i < n; i++)
    {
        vector<long long> y;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            y.push_back(x);
        }
        v.push_back(y);
    }
    // cout << "hi";
    vector<vector<long long>> v2;
    for (int i = 0; i < m; i++)
    {
        vector<long long> v1;
        for (int j = 0; j < n; j++)
        {
            v1.push_back(v[j][i]);
        }
        v2.push_back(v1);
    }
    long long res = 0;
    for (int i = 0; i < m; i++)
    {
        sort(all(v2[i]));
        for (int j = 0; j < n; j++)
        {
            res += (j * v2[i][j]) - ((n - j - 1) * v2[i][j]);
        }
    }
    cout << res << endl;
}