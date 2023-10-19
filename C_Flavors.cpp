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
bool myCmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first > b.first;

    return a.second > b.second;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(all(v), myCmp);
    int res = v[0].second;
    if (v[1].first == v[0].first)
        res += v[1].second / 2;
    else
        res += v[1].second;
    for (int i = 2; i < n; i++)
    {
        int sum = v[0].second + v[i].second;
        if (v[0].first == v[i].first)
            sum -= v[i].second / 2;
        res = max(res, sum);
    }
    cout << res << endl;
}