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
    vector<long long>adj[n+1];
    // vector<long long>v;
    for(long long i=1;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<long long>v;
    vector<long long>dist(n+1,(long long)(1e9));
    vector<long long>dist2(n+1,(long long)(1e9));
    function<void(long long,long long)>f=[&](long long i,long long p)->void{
        long long flag=0;
        for(long long v:adj[i])
        {
            if(v==p)
            continue;
            flag=1;
            dist[v]=dist[i]+1LL;
            f(v,i);
            dist2[i]=min(dist2[i],1+dist2[v]);
        }
        if(!flag)
        {
            v.push_back(i);
            dist2[i]=0;
        }
        return ;
    };
    dist[1]=0;
    f(1,-1);
   
    // for(auto it:dist)
    // cout<<it<<" ";
    // cout<<endl;
    //  for(auto it:dist2)
    // cout<<it<<" ";
    // cout<<endl;



    vector<long long>count(n+1,0);

    function<long long(long long,long long)>fa=[&](long long u,long long p)->long long{
        // long long res=1;
        long long flag=0;
        for(long long v:adj[u])
        {
            if(v==p)
            continue;
            flag=1;
            count[u]+=fa(v,u)*1LL;
        }
        long long res=count[u];
        if(!flag)
        res++;
        return res;
    };
    long long x=fa(1,-1);
    // for(auto it:count)
    // cout<<it<<" ";
    
    // cout<<endl;

    long long res=0;
    for(long long i=1;i<=n;i++)
    {
        if(dist[i]>=dist2[i] )
        {
            res=max(res,count[i]);
        }
    }
    // if(res==0)
    // res++;
    cout<<res<<endl;
}