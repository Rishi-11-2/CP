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
    long long t;
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

    long long a,b;
    cin>>a>>b;

    vector<long long>adj[n+1];

    for(long long i=1;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // if(n==2)
    // {
    //     if(a==b)
    //     cout<<1<<endl;
    //     else
    //     cout<<2<<endl;
    //     return;
    // }
    long long maxPower=log2(n)+10;
    vector<vector<long long>>parents(maxPower,vector<long long>(n+1,-1));

    vector<long long>levels(n+1,0);
    function<void(long long,long long,long long)>dfs=[&](long long u,long long p,long long level)->void{

        levels[u]=level;
        if(p!=-1)
        {
            parents[0][u]=p;
        }
        for(long long v:adj[u])
        {
            if(v==p)
            continue;
            
            dfs(v,u,level+1);
        }
    };

    dfs(1,-1,0);
    for(long long i=1;i<maxPower;i++)
    {
        for(long long node=1;node<=n;node++)
        {
            long long inermediate=parents[i-1][node];
            if(inermediate!=-1)
            {
                parents[i][node]=parents[i-1][inermediate];
            }
        }
    }

    function<long long(long long,long long)>f=[&](long long node,long long k)->long long{

        for(long long i=0;i<maxPower;i++)
        {
            if(k&(1<<i))
            {
                node=parents[i][node];
                if(node==-1)
                return node;
            }
        }
        return node;
    };

    function<long long(long long,long long)>lca=[&](long long a,long long b)->long long{

        if(levels[a]>levels[b])
        {
            a=f(a,levels[a]-levels[b]);
        }
        else if(levels[b]>levels[a])
        {
            b=f(b,levels[b]-levels[a]);
        }

        if(a==b)
        {
            return a;
        }
        for(long long i=maxPower-1;i>=0;i--)
        {
            long long ax=parents[i][a];
            long long bx=parents[i][b];
            if(ax!=bx)
            {
                a=ax;
                b=bx;
            }
        }

        return parents[0][a];
    };

    long long c=lca(a,b);
    // debug(a,b,c);
    long long dist=levels[a]+levels[b]-2*levels[c];
    

    long long res=0;
    // debug(dist);4
    
    long long len=(dist+1)/2;
    // debug(len);
    res=len;

    dist++;
    if(a!=b)
    {
        len=(dist+1)/2;
        int d1=levels[a]-levels[c]+1;
        if(len<=d1)
        {
            b=f(a,len-1);
        }
        else{
            len-=d1;
            int l=levels[b]-levels[c];
            l-=len;
            b=f(b,l);
        }
    }
    // debug((dist+1)/2);
   
    // debug(b);
    vector<long long>count(n+1,(long long)(1e9));
    
    queue<long long>q2;

    q2.push(b);
    count[b]=0;
    while(!q2.empty())
    {
        long long u=q2.front();
        q2.pop();
        for(long long v:adj[u])
        {
            if(count[v]>(count[u]+1))
            {
                count[v]=count[u]+1;
                q2.push(v);
            }
        }
    }
    long long maxm=0;
    for(long long i=1;i<=n;i++)
    {
        maxm=max(maxm,count[i]);
    }
    long long y=2*(n-1);
    y-=maxm;
    // debug(maxm);
    // debug(res);
    res+=y;
    cout<<res<<endl;
}