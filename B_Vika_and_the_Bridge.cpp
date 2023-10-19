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
    int n, k;
    cin >> n >> k;
    vector<priority_queue<int>> v(k + 1, priority_queue<int>());

    int prev[k + 1];
    memset(prev, -1, sizeof(prev));

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[x].push((i - prev[x]) - 1);
        prev[x] = i;
    }
    for (int i = 1; i <= k; i++)
    {
        v[i].push(n - prev[i] - 1);
    }
    int minm = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (v[i].empty())
            continue;
        int x = v[i].top();
        x = x - 1;
        int y = x / 2;
        int z = x - y;
        v[i].pop();
        v[i].push(y);
        v[i].push(z);
        minm = min(minm, v[i].top());
    }
    cout << minm << endl;
}