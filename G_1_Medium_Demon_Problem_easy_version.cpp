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
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{

    long long n;
    cin>>n;

    vector<long long>indegree(n+1,0);

    vector<long long>adj[n+1];
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin>>x;

        adj[i].push_back(x);

        indegree[x]++;
    }


    long long y=1;

    queue<long long>q;
    
    for(long long i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {

        long long c=(long long)q.size();
        y++;
        for(long long i=1;i<=c;i++)
        {
            long long u=q.front();
            // debug(u);
            q.pop();
            for(long long v:adj[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                q.push(v);
            }
        }
    }

    cout<<y+1<<endl;


}