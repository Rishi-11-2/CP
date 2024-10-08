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
    long long n,k;
    cin>>n>>k;

    long long a[n];
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    long long b[n];
    for(long long i=0;i<n;i++)
    {
        cin>>b[i];
    }


    long long low=0;
    long long high=(long long)(1e10);

    function<long long(long long)>f=[&](long long mid)->long long{
        long long count=0;
        for(long long i=0;i<n;i++)
        {
            if(a[i]<mid)
            continue;
            long long cc=((a[i]-mid)/b[i])+1;
            count+=cc;
        }
        if(count>=k)
        return 1;
        return 0;
    };
    long long res=0;
    while(low<=high)
    {
        long long mid=(low+high)/2;
        if(f(mid))
        {
            res=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    function<long long(long long,long long,long long)>summ=[&](long long a,long long d,long long count)->long long{

        long long sum=2*a-(count-1)*d;
        sum=sum*count;
        sum=sum/(2LL);
        return sum;
    };
    long long tc=0;
    long long ans=0;
    for(long long i=0;i<n;i++)
    {
        if(a[i]<(res+1))
        continue;
        long long count=((a[i]-(res+1))/b[i])+1;

        tc+=count;
        // debug(i,count,summ(a[i],b[i],count));
        ans+=summ(a[i],b[i],count);
    }

    // debug(res);

    ans+=(k-tc)*res;
    cout<<ans<<endl;
}