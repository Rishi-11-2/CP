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
        solve();
}
long long dp[103][103][103][4];
long long arr[1000];
long long f(long long i,long long ce,long long co,long long prev,long long n)
{
    if(i==n)
    {
        return 0;
    }
    if(dp[i][ce][co][prev+1]!=-1)
    return dp[i][ce][co][prev+1];
    long long res=(long long)(1e9);
    if(arr[i]!=0)
    {
        long long curr=arr[i]%2;
        if(prev!=curr && prev!=-1)
        {
        res=min(res,1+f(i+1,ce,co,curr,n));
        }
        else
        {
        res=min(res,f(i+1,ce,co,curr,n));
        }
    }
    else
    {
        long long x=(long long)(1e9);
        long long y=(long long)(1e9);
        if(prev==-1)
        {
            if(ce>0)
            x=f(i+1,ce-1,co,0,n);
            if(co>0)
            y=f(i+1,ce,co-1,1,n);
        }
        else if(prev==0)
        {
            if(ce>0)
            x=f(i+1,ce-1,co,0,n);
            if(co>0)
            y=1+f(i+1,ce,co-1,1,n);
        }
        else
        {
            if(ce>0)
            x=1+f(i+1,ce-1,co,0,n);

            if(co>0)
            y=f(i+1,ce,co-1,1,n);
        }

        res=min(x,y);

    }
    return dp[i][ce][co][prev+1]= res;
}
void solve()
{
    long long n;
    cin>>n;


    for(long long i=0;i<n;i++)
    cin>>arr[i];


    set<long long>s;
    for(long long i=1;i<=n;i++)
    s.insert(i);
    
    for(long long i=0;i<n;i++)
    {
        if(arr[i]==0)
        continue;
        s.erase(s.find(arr[i]));
    }

    long long ce=0;
    long long co=0;
    for(auto it:s)
    {
        if(it%2)
        co++;
        else
        ce++;
    }
    // debug(ce,co);
    memset(dp,-1,sizeof(dp));
    long long x=f(0,ce,co,-1,n);
    cout<<x<<endl;
}