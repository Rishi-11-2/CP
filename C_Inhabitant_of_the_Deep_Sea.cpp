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

    long long arr[n];
    vector<long long>count(n,0);
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        count[i]=arr[i];
    }
    long long first=k/2;
    long long last=k/2;
    if(k%2)
    first++;
     
    long long s=0;
    long long fc=0;
    for(long long i=0;i<n;i++)
    {
        long long d=min(count[i],first);
        count[i]-=d;
        first-=d;
        // debug(first,i);
        if(first==0)
        break;
    }
    s=0;
    long long lc=0;
    for(long long i=n-1;i>=0;i--)
    {
        long long d=min(count[i],last);
        count[i]-=d;
        last-=d;
        if(last==0)
        break;
    }
    // for(long long i=0;i<n;i++)
    // cout<<count[i]<<" ";
    // cout<<endl;
    long long res=0;
    for(long long i=0;i<n;i++)
    {
        if(count[i]==0)
        res++;
    }
    cout<<res<<endl;
}