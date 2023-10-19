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
    vector<set<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            int y;
            cin >> y;
            v[i].insert(y);
        }
    }
    int x;
    cin >> x;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int sz = (int)(v[i].size());
        if (v[i].find(x) != v[i].end())
        {
            mp[sz].push_back(i + 1);
        }
    }
    int flag = 0;
    for (auto it : mp)
    {
        flag = 1;
        cout << it.second.size() << endl;
        for (auto i : it.second)
        {
            cout << i << " ";
        }
        break;
    }
    if (flag == 0)
        cout << 0;
    cout << endl;
}