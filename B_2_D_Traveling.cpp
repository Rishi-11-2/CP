#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> v;
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        if (i == a)
            start = {x, y};
        if (i == b)
            end = {x, y};
        mp[{x, y}] = i;
    }
    vector<int> dist(n + 1, 0x3f3f3f3f);
    dist[a] = 0;
    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y = it.second;
        
    }
}