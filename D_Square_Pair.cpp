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
    
    // cout<<endl;
    long long ans=0;
    long long count=0;
    vector<long long>v;
    for(long long j=0;j<n;j++)
    {
        if(arr[j]==0)
        {
           count++;
            // continue;
        }
        else
        {
            v.push_back(arr[j]);
        }
    }
    // debug(count);
    ans+=(count*(count-1))/2LL;
    ans+=(count*(n-count));
    // debug(ans);
    long long mm=(long long)(v.size());
    // debug(mm);
    for(long long j=0;j<mm;j++)
    {
        long long x=v[j];
        long long f=0;
        while(x%2==0)
        {
            f++;
            x=x/2;
        }
        for(long long i=3;i*i<=x;i+=2)
        {
            long long f1=0;
            while(x%i==0)
            {
                f1++;
                x/=i;
            }
            if(f1%2)
            {
                x=x*i;
            }
        }
        if(f%2)
        x=x*2;
        v[j]=x;
        // mp[x]++;
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
        // debug(x);
        x=x/2LL;
        // debug(x);
        ans+=x;
    }
    cout<<ans<<endl;
}