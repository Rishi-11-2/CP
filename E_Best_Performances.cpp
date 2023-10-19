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
    int n, k, q;
    cin >> n >> k >> q;
    set<int> s;
    int minm = INT_MAX;
    int sum = 0;
    map<int, int> mp;
    vector<int> res;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x] = y;
        sum += y;
        minm = min(minm, y);
        res.push_back(sum);
    }
    for (int i = k + 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        
    }
}