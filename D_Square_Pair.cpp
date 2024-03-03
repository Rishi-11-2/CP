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
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    

    long long m=(long long)(2e5+10);
    bool isPrime[m];
    for(long long i=0;i<=m;i++)
    {
        isPrime[i]=1;
    }
    isPrime[0]=isPrime[1]=0;
    // debug("hi");
    for(long long i=2;i*i<=m;i++)
    {
        if(isPrime[i])
        {
            for(long long j=i*i;j<=m;j+=i)
            {
                isPrime[j]=0;
            }
        }
    }
    // debug("hi");
    vector<long long>primes;
    for(long long i=2;i<=m;i++)
    {
        if(isPrime[i])
        primes.push_back(i);
    }
    // for(auto i:primes)
    // {
    //     cout<<i<<" ";
    // debug(primes.size());
    // }
    // cout<<endl;
    long long ans=0;
    vector<long long>v;
    for(long long j=0;j<n;j++)
    {
        if(arr[j]==0)
        {
            ans+=((n-1)-j)*1LL;
            // continue;
        }
        else
        {
            v.push_back(arr[j]);
        }
    }
    long long mm=(long long)(v.size());
    // debug(mm);
    for(long long j=0;j<mm;j++)
    {
        for(auto i:primes)
        {
            if(v[j]<i)
            break;
            long long count=0;
            while(v[j]%i==0)
            {
                count++;
                v[j]/=i;
            }
        // debug(count);
            if(count&1)
            {
                v[j]=v[j]*i;
            }

        // debug(arr[j]);
        }
    }
    // debug(ans);
    map<long long,long long>mp;
    for(long long i=0;i<mm;i++)
    {
        mp[v[i]]++;
    }

    for(auto it:mp)
    {
        long long count=it.second;
        long long x=(count)*(count-1);
        x=x/2LL;

        ans+=x;
    }
    cout<<ans<<endl;
}