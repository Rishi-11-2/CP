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
    long long n;
    cin>>n;
    long long x[n];

    for(long long i=0;i<n;i++)
    cin>>x[i];

    long long p[n];

    for(long long i=0;i<n;i++)
    cin>>p[i];
     
    /* LL 
       RR
       LR*/

    /*L->0
      R->1*/

    long long res=0;
    /*LL case*/
    long long prev=x[0];
    long long count=0;

    vector<long long>left(n,0);
    vector<long long>right(n,0);

    for(long long i =1;i<n;i++)
    {
        long long d=max(prev,x[i]-p[i]);
        if(d>prev)
        {
            count++;
        }
        left[i]=count;
        prev=x[i];
    }
    if(count<=1)
    {
        res=1;
    }

    // debug(res);
    /*RR case*/

    // long long next=x[];
    count=0;

    for(long long i=n-2;i>=0;i--)
    {
        long long next=x[i+1];
        long long d=min(next,x[i]+p[i]);
        if(d<next)
        {
            count++;

        }
        right[i]=count;
    }

    if(count<=1)
    {
        res=1;
    }

    // debug(res);
    // for(long long i=0;i<n;i++)
    

    // RL

    long long next=x[1];
    long long idx=-1;

    for(long long i=0;i<n-1;i++)
    {
        next=x[i+1];
        long long d=min(next,x[i]+p[i]);
        if(d<next)
        {
            idx=i+1;
            break;
        }
    }

    long long idx1=-1;

    // long long prev=x[n-1];
    for(long long i=n-1;i>=idx;i--)
    {
        long long prev=x[i-1];

        long long d=max(prev,x[i]-p[i]);
        
        if(d>prev)
        {
            idx1=i;
            break;
        }
        idx1=i;
    }

    if(idx==idx1)
    {
        res=1;

    }


     // LR

    idx=-1;

    idx1=-1;
    for(long long i=1;i<n;i++)
    {
        long long prev=x[i-1];

        long long d=max(prev,x[i]-p[i]);

        if(d>prev)
        {
            idx=i;
            break;
        }
    }

    for(long long i=idx;i<n-1;i++)
    {
        long long next=x[i+1];
        long long d=min(next,x[i]+p[i]);

        if(d<next)
        {
            break;
        }
        idx1=i;
    }

    if(idx1==n-2)
    {
        res=1;
    }
    // debug(res);
    if(res)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}