#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
bool sorter(set<int> a, set<int> b)
{
    return a.size() < b.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
void solve()
{
    int n, m;
    cin >> n >> m;
    set<int> u;
    for (int i = 1; i <= m; i++)
        u.insert(i);
    vector<set<int>> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int nn;
        cin >> nn;
        for (int j = 1; j <= nn; j++)
        {
            int x;
            cin >> x;
            v[i].insert(x);
        }
    }
    sort(all(v), sorter);
    auto p = v[v.size() - 1];
    auto q = p;
    for (auto &it : q)
    {
        u.erase(it);
    }
    if (u.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    int c = 0;
    for(int i=m-2;i>=0;i--)
    {
        
    }
}