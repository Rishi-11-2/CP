#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// long long getRandomNumber(long long l, long long r) {return uniform_long long_distribution<long long>(l, r)(rng);}
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
    long long a[n],b[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    
    for(long long i=0;i<n;i++)
    cin>>b[i];
    vector<long long>prefix(n+1,0);
    // prefix[0]=b[0];
    for(long long i=0;i<n;i++)
    prefix[i+1]=prefix[i]+b[i];
    vector<long long>count(n+1,0);
    vector<long long>add(n+1,0);
    for(long long i=0;i<n;i++)
    {
        long long j=upper_bound(prefix.begin(),prefix.end(),a[i]+prefix[i])-prefix.begin()-1;
        add[j]+=a[i]-prefix[j]+prefix[i];
        count[i]+=1;
        count[j]-=1;
    }

    for(long long i=0;i<n;i++)
    {
        cout<<add[i]+b[i]*count[i]<<" ";
        count[i+1]+=count[i];
    }
    cout<<endl;
}