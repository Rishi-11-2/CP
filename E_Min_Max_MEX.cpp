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

    vector<long long>arr(n);

    for(long long i=0;i<n;i++)
    cin>>arr[i];

    auto f=[&](long long mex,auto&& f)->long long{
    
        long long count=0;
        
        set<long long>s;

        long long res=0;
        for(long long i=0;i<n;i++)
        {
            s.insert(arr[i]);
            while(s.find(res)!=s.end())
            {
                s.erase(res);
                res++;
            }
            if(res>=mex)
            {
                s.clear();
                count++;
                res=0;
            }
            // debug(i,res,count,mex);
        }
        if(count>=k)
        return 1;

        return 0;
    };

    long long low=0;
    long long high=n;

    long long res=0;
    // debug(f(3,f));
    while(low<=high)
    {
        long long mid=(low+high)/2;
        // debug(mid,f(mid,f));
        if(f(mid,f))
        {
            res=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    cout<<res<<endl;
}