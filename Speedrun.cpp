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

    long long x[n];
    for(long long i=0;i<n;i++)
    cin>>x[i];
    

    long long h[n];

    for(long long i=0;i<n;i++)
    cin>>h[i];

    
    long long p_sum=0;

    long long idx=-1;

    for(long long i=0;i<n;i++)
    {
        
        p_sum+=h[i];
        if(x[i]-p_sum<0)
        {
           idx=i;
           break;   
        }
    }

    if(idx==-1)
    {
        cout<<"YES"<<endl;
        return;
    }
    long long i=idx;
    while(i<n && x[idx]+2*k>=x[i])
    {
        i++;
    }
    long long kk=i-1;

    for(long long j=kk;j>=0;j--)
    {
        if(x[j]+2*k>=x[kk])
        {
            h[j]=0;
        }
        else
        break;
    }

    long long prev=0;
    for(long long i=0;i<n;i++)
    {
        prev+=h[i];
        if(prev>x[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}