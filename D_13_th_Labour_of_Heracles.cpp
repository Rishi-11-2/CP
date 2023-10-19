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
    long long n;
    cin >> n;
    long long arr[n + 1];
    for (long long i = 1; i <= n; i++)
        cin >> arr[i];
    vector<long long> adj[n + 1];
    for (int i = 1; i <= n - 1; i++)
    {
        long long x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<long long> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 1)
        {
            vis[i] = 1;
        }
    }
    vector<long long> v;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            v.push_back(arr[i]);
        }
    }
    sort(all(v), greater<int>());
    long long s = 0LL;
    for (int i = 1; i <= n; i++)
        s += arr[i];
    cout << s << " ";
    long long curr = 0;
    long long flag = 0;
    long long sz = (long long)(v.size());
    for (int i = 2; i < n; i++)
    {
        s += v[curr];
        if (flag == 0)
            curr++;
        if (curr == sz && flag == 0)
        {
            flag = 1;
            curr = 0;
        }
        cout << s << " ";
    }
    cout << endl;
}