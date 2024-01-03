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
bool isPrime(long long i)
{
    for(long long j=2;j<i;j++)
    {
        if(i%j==0)
        return 0;
    }
    return 1;
}
long long binpow(long long a,long long b,long long mod)
{
    long long res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(res%mod*a%mod)%mod;
        }
        a=(a%mod*(a%mod))%mod;
        b>>=1;
    }

    return res;
}
void solve()
{
    long long n;
    cin>>n;
    long long arr[n];
    unordered_map<long long,long long>mp;
    // for(long long i=1;i<=70;i++)
    // {
    //     mp[i]=
    // }
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }

    const long long mod=(long long)(1e9+7);
    long long count=0;
    vector<long long>mask(80,0);
    vector<long long>countP(80,0);

    for(int i=1;i<=70;i++)
    {
        if(mp[i]==0)
        continue;
        countP[i]=binpow(2,mp[i]-1,mod);
    }
    for(long long j=2;j<71;j++)
    {
        if(!isPrime(j))
        continue;
        for(long long i=1;i<71;i++)
        {
            long long x=i;
            while(x%j==0)
            {
                x/=j;
                mask[i]^=(1<<count);
            }
        }
        count++;
    }



    /* states (i,mask)*/
    vector<long long>prev((1<<20)+1,0);
    vector<long long>curr((1<<20)+1,0);
    /*dp[i][mask]+=dp[i-1][mask]*2^(mp[arr[i]]-1)*/
    prev[0]=1;
    for(long long i=1;i<=70;i++)
    {
        for(long long j=0;j<((1<<20)*1LL);j++)
        {
            if(mp[i]==0)
            {
                curr[j]=(curr[j]%mod+prev[j])%mod;
            }
            else
            {
                curr[j]=(curr[j]%mod+(prev[j]%mod*countP[i]%mod)%mod)%mod;
                curr[j^mask[i]]=(curr[j^mask[i]]%mod+(prev[j]%mod*countP[i]%mod))%mod;
            }
            // if(i==1)
            // debug()
        }
            // debug(curr[0]);
        prev=curr;
        curr.assign((1<<20)+1,0);
    }

    cout<<prev[0]-1<<endl;
}