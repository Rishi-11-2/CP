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
    long long n,m;
    cin>>n>>m;
    long long arr[n];

    for(long long i=0;i<n;i++)
    cin>>arr[i];

    
    map<long long,long long>mp;
    map<long long,long long>f;

    long long sz=m;
    for(long long i=1;i<=m;i++)
    {
        long long x;
        cin>>x;
        f[i]=x;
        if(f[i]==0)
        sz--;
    }


    long long i=0;
    long long j=0;
    long long res=(long long)(1e12);
    long long extra=0;
    set<long long>s;

    while(j<n)
    {
        mp[arr[j]]++;
        // debug(mp[arr[j]],arr[j]);
        if(mp[arr[j]]==f[arr[j]])
        {
            // debug(arr[j]);d
            s.insert(arr[j]);
            
        }
        
        if(mp[arr[j]]>f[arr[j]])
        {
            extra++;
        }


        while(i<=j )
        {
            // debug(i,j);

            if((long long)(s.size())==sz)
            res=min(res,extra);
        
            mp[arr[i]]--;
            extra--;
            if(mp[arr[i]]<f[arr[i]])
            {
                extra++;
                mp[arr[i]]++;
                break;
            }
            i++;
        }

        j++;
    }

    // if((long long)(s.size())==m)
    // {
    //     res=0;
    // 

    if(res==(long long)(1e12))
    {
        res=-1;
    }

    cout<<res<<endl;

}