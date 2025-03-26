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
    vector<long long>arr(k);

    for(long long i=0;i<k;i++)
    {
        cin>>arr[i];
        arr[i]=min(arr[i],n-1);
    }


    sort(all(arr));

    vector<long long>prefix(k,0);
    for(long long i=0;i<k;i++)
    {
        prefix[i]=arr[i];
        if(i)
        {
            prefix[i]+=prefix[i-1];
        }
    }

    function<long long(long long)>f=[&](long long i)->long long{
        long long low=i+1;
        long long high=k-1;

        long long res=k;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            if((arr[mid]+arr[i])>=n)
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return res;
    };
    long long res=0;
    for(long long i=0;i<k;i++)
    {
        long long idx=f(i);

        if(idx==k)
        continue;


        long long count=k-idx;

        long long d=prefix[k-1];
        if(idx>=1)
        d-=prefix[idx-1];

        d+=count*arr[i];
        
        d=d-(count)*n+count;


        d=d*2;

        res+=d;
    }

    cout<<res<<endl;

    
}