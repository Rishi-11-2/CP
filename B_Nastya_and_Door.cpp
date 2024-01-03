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
    long long n,k;
    cin>>n>>k;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    
    long long low=0;
    long long high=n;
    long long res=0;
    long long left=-1;
    long long l=-1;
    function<long long(long long)>f=[&](long long mid)->long long{
        long long count=0;
        l=-1;
        set<long long>s;
        for(long long i=0;i<k;i++)
        {
            if(i>0 && i<k-1)
            {
                if(a[i]>a[i-1] && a[i]>a[i+1])
                {
                    count++;
                    s.insert(i);
                }
            }
        }
        if(count+1>=mid)
        {
            l=0;
            return 1;
        }
        for(long long i=k;i<n;i++)
        {
            if(s.find(i-k+1)!=s.end())
            {
                count--;
            }
            if(s.find(i-k)!=s.end())
            {
                s.erase(i-k);
            }
            if(a[i-1]>a[i-2] && a[i-1]>a[i])
            {
                s.insert(i-1);
                count++;
            }

           if(count+1>=mid)
           {
                l=(i-k+1);
                return 1;
           }
        }
        return 0;
    };
    while(low<=high)
    {
        long long mid=(low+high)/2;
        if(f(mid))
        {
            left=l;
            res=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    cout<<res<<" "<<left+1<<endl;

}