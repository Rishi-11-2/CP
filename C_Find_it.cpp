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
vector<int> ans;
void dfs(vector<int> adj[], int i, vector<int> &vis, vector<int> &res, stack<int> &st, int flag)
{
    if (flag == 1)
        return;
    vis[i] = 1;
    res[i] = 1;
    for (int v : adj[i])
    {
        if (vis[v] == 0)
        {
            st.push(v);
            dfs(adj, v, vis, res, st, flag);
        }
        else if (res[v] == 1)
        {
            while (!st.empty() && st.top() != v)
            {
                ans.push_back(st.top());
                st.pop();
            }
            ans.push_back(v);
            reverse(all(ans));
            // for (auto it : ans)
            //     cout << it << " ";
            // cout << endl;
            flag = 1;
            return;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    ans.resize(0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[i].push_back(x);
    }
    vector<int> vis(n + 1, 0);
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        stack<int> st;
        if (vis[i] == 0)
        {
            st.push(i);
            dfs(adj, i, vis, res, st, 0);
            if (res.size() > 0)
            {
                cout << ans.size() << endl;
                // sort(all(ans));
                for (auto it : ans)
                    cout << it << " ";
                cout << endl;
                return;
            }
        }
    }
}