#pragma GCC optimize("O3","unroll-loops")
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
long long m=(long long)(1e7+10);
vector<long long>isPrime(m+1,1);
vector<long long>minm(m+1,(long long)(1e9));
// vector<long long>primes;
  void sieve()
{
    isPrime[0]=isPrime[1]=0;
    minm[0]=1;
    minm[1]=1;
    for(long long i=2;i<=m;i++)
    {
        minm[i]=i;
    }
    for(long long i=2;i*i<=m;i++)
    {
        if(isPrime[i])
        {
            minm[i]=i;
            for(long long j=i*i;j<=m;j+=i)
            {
                // cout<<j<<endl;   
                minm[j]=min(minm[j],i);
                isPrime[j]=0;
            }
        }
    }
    // cout<<minm[200001]<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(10);
        solve();
}
 long long f(long long i,long long z)
 {
        // long long mm=minm[i];
        long long x=i;
        vector<long long>res;
        // set<long long>s;
        while(i>1)
        {
        // debug(i);
          if(res.empty() || res.back()!=minm[i])
           res.push_back(minm[i]);
           i/=minm[i];
        }
        // vector<long long>res(all(s));
        long long ans=INT_MAX;
        for(auto i:res)
        {
            long long y=(i+z-1)/i;
            ans=min(ans,i*y-z);
        }
        return ans;
 }
 void solve()
{
    long long n;
    cin>>n;
    sieve();
    vector<long long>ans(n,0);
    for(long long i=0;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        long long diff=y-x;
        // debug(vv[i]);
        // debug(diff);
        if(diff==1)
        {
            ans[i]=-1;
        }
        else if(__gcd(x,y)>1)
        {
            ans[i]=0;
        }
        else
        {
            // cout<<"hi"<<endl;
           ans[i]=f(diff,x);
        }
    }
    for(auto it:ans)
    {
        cout<<it<<'\n';
    }
    // cout<<endl;
}