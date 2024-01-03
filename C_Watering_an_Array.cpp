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
    long long n,k,d;
    cin>>n>>k>>d;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    long long b[k];

    for(long long i=0;i<k;i++)
    cin>>b[i];
    
    long long res=0;
    long long days=1;
    long long ans=0;
    for(long long i=0;i<n;i++)
    {
        if(arr[i]==(i+1))
        {
            // days=1;
            res++;
        }
    }
    long long rest=max(0LL,(d-days)/(2*1LL));
            // days=j+2;
    ans=max(ans,res+rest);
    // debug(ans);
    long long flag=1;
    long long j=0;
    while(j<=(3*n))
    {
        for(long long i=0;i<b[j%k];i++)
        {
            arr[i]+=1;
        }
        long long count=0;
        // flag=0;
        for(long long i=0;i<n;i++)
        {
            if(arr[i]==(i+1))
            {
                count++;
            }
        }
        // if(arr[0]>n)
        // {
        //     flag=0;
        // }
        if((j+2)<=d)
        {
            res=count;
            days=j+2;
            long long rest=max(0LL,(d-days)/(2*1LL));
            ans=max(ans,res+rest);
        }
        j=(j+1);
        // if(!flag)
        // break;
    }
    // if(days==0)
    // days=+1;
    // debug(rest,days,d);
    cout<<ans<<endl;

}