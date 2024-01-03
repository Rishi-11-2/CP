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
    long long n,k;
    cin>>n>>k;
    long long a[k];
    for(long long i=0;i<k;i++)
    {
        cin>>a[i];
    }
    sort(a,a+k);
    if(k==1)
    {
        cout<<0<<endl;
        return;
    }
    if(k%2==0)
    {
        long long s=0;
        for(long long i=0;i<k;i+=2)
        {
            s+=(a[i+1]-a[i]);
        }
        cout<<s<<endl;
        return;
    }
    vector<long long>prefix(k,0);
    vector<long long>suffix(k,0);
    prefix[0]=0;
    prefix[1]=a[1]-a[0];
    for(long long i=2;i<k;i++)
    {
        prefix[i]=prefix[i-2]+(a[i]-a[i-1]);
    }
    suffix[k-1]=0;
    suffix[k-2]=a[k-1]-a[k-2];
    for(long long i=k-3;i>=0;i--)
    {
        suffix[i]=suffix[i+2]+(a[i+1]-a[i]);
    }
    long long res=min({suffix[0],suffix[1],prefix[k-1],prefix[k-2]});
    for(long long i=2;i<k-2;i+=2)
    {
        res=min(res,suffix[i+1]+prefix[i-1]);
    }
    cout<<res<<endl;
}