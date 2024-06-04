#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
   
        solve();
}
void solve()
{
    int n;
    cin >> n;

    vector<int> adj[n + 1];
    vector<int> adj_rev[n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                adj[i].push_back(j);
                adj_rev[j].push_back(i);
            }
        }
    }

    vector<int> order;
    vector<int> vis(n + 1, 0);
    function<void(int)> f = [&](int u) -> void
    {
        vis[u] = 1;
        for (int v : adj[u])
        {
            if (!vis[v])
            {
                f(v);
            }
        }
        order.push_back(u);
    };

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            f(i);
        }
    }
    reverse(order.begin(), order.end());
    vis.assign(n + 1,0);

    int component_no = 1;
    map<int, int> mp;
    function<void(int)> dfs = [&](int u) -> void
    {
        vis[u] = 1;
        mp[u] = component_no;
        for (int v : adj_rev[u])
        {
            if (!vis[v])
            {
                dfs(v);
            }
        }
    };

    for (auto it : order) {
        if (vis[it]) continue;
        dfs(it);
        component_no++;
    }


    vector<int> adj_scc[n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int v : adj[i])
        {
            if (mp[i] == mp[v])
            {
                adj_scc[i].push_back(v);
            }
        }
    }

    vector<int> ans(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        queue<int> q;
        q.push(i);

        vector<int> dist(n + 1, (int)(1e9));
        dist[i] = 0;
        int flag = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (flag)
                break;
            for (int v : adj_scc[u])
            {
                if (flag) break;
                if (dist[v] > (dist[u] + 1))
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
                if (v == i)
                {
                    ans[i] = dist[u] + 1;
                    flag = 1;
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == -1)
        {
            cout << "NO WAY" << '\n';
        }
        else
        {
            cout << ans[i] << '\n';
        }
    }

}