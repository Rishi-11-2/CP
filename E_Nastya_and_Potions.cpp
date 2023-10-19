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
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    long long b[k];
    vector<long long> vis(n + 1, 0);
    for (long long i = 0; i < k; i++)
    {
        cin >> b[i];
        vis[b[i]] = 1;
    }
    vector<long long> adj[n + 1];
    vector<long long> listA[n + 1];
    vector<long long> in(n + 1, 0);
    queue<long long> q;
    for (long long i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        for (long long k = 1; k <= x; k++)
        {
            long long y;
            cin >> y;
            in[i]++;
            adj[y].push_back(i);
            listA[i].push_back(y);
            // adj[i].push_back(y);
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " ";
    //     for (int j = 0; j < adj[i].size(); j++)
    //         cout << adj[i][j] << " ";
    //     cout << endl;
    // }
    vector<long long> res(n + 1, 0);
    for (long long i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            // cout << i << " ";
            q.push(i);
        }
        if (vis[i] == 1)
            res[i] = 0;
    }
    // cout << endl;
    vector<long long> x;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        x.push_back(it);
        for (long long v : adj[it])
        {
            in[v]--;
            if (in[v] == 0)
            {
                q.push(v);
            }
        }
    }
    // for (auto it : x)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    for (auto it : x)
    {
        if (vis[it] == 1)
            res[it] = 0;
        else
        {
            long long l = 0;
            long long flag = 0;
            for (long long v : listA[it])
            {
                // cout << it << "  " << v << endl;
                l += res[v];
                flag = 1;
            }
            if (!flag)
                l = INT_MAX;
            // cout << l << endl;
            res[it] = min(arr[it - 1], l);
        }
    }
    for (long long i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;
}