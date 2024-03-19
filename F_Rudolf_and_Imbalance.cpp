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
//(data type to be stored (pair,long long ,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong long s)
typedef tree < pair<long long ,long long >, null_type,less<pair<long long ,long long >>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long  t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long  n,m,k;
    cin>>n>>m>>k;
    long long  a[n];
    for(long long  i=0;i<n;i++)
    cin>>a[i];
    
    long long  d[m];

    for(long long  i=0;i<m;i++)
    cin>>d[i];
    
    long long  f[k];


    set<long long >s;
    for(long long  i=0;i<k;i++)
    {
        cin>>f[i];
        s.insert(f[i]);
    }
    

    sort(d,d+m);
    sort(f,f+k);


    function<long long (long long )>f1=[&](long long  mid)->long long {

        long long  c=0;
        long long  minm=-1;
        long long  maxm=-1;
        for(long long  i=0;i<n-1;i++)
        {
            if(a[i+1]-a[i]>mid)
            {
                c++;
                minm=a[i];
                maxm=a[i+1];
            }
            if(c>=2)
            return 0;
        }

        long long  target1=maxm-mid;
        long long  target2=minm+mid;

        for(long long  i=0;i<m;i++)
        {
            if(d[i]<target1)
            {
                long long  r=target1-d[i];
                if(s.find(r)!=s.end())
                {
                    long long  xx=max(maxm-target1,target1-minm);
                    if(xx<=mid)
                    return 1;
                }
            }
            if(d[i]<target2)
            {
                long long  r=target2-d[i];
                if(s.find(r)!=s.end())
                {
                    long long  xx=max(maxm-target2,target2-minm);
                    if(xx<=mid)
                    return 1;
                }
            }
        }

        return 0;
    };
    long long  minm=0;
    for(long long  i=0;i<n-1;i++)
    {
        minm=max(minm,a[i+1]-a[i]);
    }
    long long  high=minm;
    long long  res=minm;
    long long  low=0;

    while(low<=high)
    {
        long long  mid=(low+high)/2LL;
        // debug(mid);
        if(f1(mid))
        {
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<res<<endl;

}