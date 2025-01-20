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

    long long arr[n];

    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    long long i=0;
    vector<long long>v;
    long long s=0;
    map<long long,long long>mp;
    map<int,int>mp1;
    while(i<n)
    {
        long long j=i;
        long long sum=0;
        long long count=0;
        while(i<n && (arr[i]==arr[j]))
        {
            count++;
            sum+=arr[i];
            i++;
        }

        long long sz=(long long)v.size();
        if(count%2)
        v.push_back(arr[j]);
        else
        v.push_back(0);
        mp[sz]=sum;
        mp1[sz]=arr[j];
    }
    n=(long long)v.size();
    vector<long long>prefix(n);
    vector<long long>suffix(n);
    for(long long i=0;i<n;i++)
    {
        prefix[i]=v[i];
        if(i)
        {
            prefix[i]^=prefix[i-1];
        }
    }

    for(long long i=n-1;i>=0;i--)
    {
        suffix[i]=v[i];
        if(i<n-1)
        {
            suffix[i]^=suffix[i+1];
        }
    }
    // for(auto it:v)
    // cout<<it<<" ";
    // cout<<endl;
    long long ans=0;
    for(long long i=0;i<n;i++)
    {
        long long x=0;
        if(i>0 && prefix[i-1]==mp1[i])
        {
            // debug(i,prefix[i-1]);
            x+=mp[0];
        }
        if(i<(n-1) && suffix[i+1]==mp1[i])
        {
            // debug(i,suffix[i+1]);
            x+=(mp[n-1]);
        }
        x+=mp[i];

        ans=max(ans,x);
    }

    cout<<ans<<endl;
}