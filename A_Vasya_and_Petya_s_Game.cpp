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
void solve()
{
    long long n;
    cin>>n;
    vector<long long>vis(n+1,0);
    vector<long long>isPrime(n+1,1);
    isPrime[0]=isPrime[1]=0;
    for(long long i=2;i*i<=n;i++)
    {
        if(isPrime[i])
        {
            for(long long j=i*i;j<=n;j+=i)
            {
                isPrime[j]=0;
            }
        }
    }
    for(long long i=2;i<=n;i++)
    {
        if(isPrime[i])
        {
            vis[i]=1;
            int k=i*i;
            while(k<=n)
            {
                vis[k]=1;
                k*=i;
            }
        }
    }
    vector<long long>res;
    for(long long i=2;i<=n;i++)
    {
        if(vis[i])
        res.push_back(i);
    }
    cout<<(long long)(res.size())<<endl;
    for(auto it:res)
    cout<<it<<" ";
    cout<<endl;
}