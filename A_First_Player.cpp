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
    vector<pair<string, int>> v;
    int idx = -1;
    int p = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        string s;
        int a;
        cin >> s >> a;
        v.push_back({s, a});
        if (a < p)
        {
            p = a;
            idx = i - 1;
        }
    }
    for (int i = idx; i < v.size(); i++)
    {
        cout << v[i].first << endl;
    }
    for (int i = 0; i < idx; i++)
    {
        cout << v[i].first << endl;
    }
}