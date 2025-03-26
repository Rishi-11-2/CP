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
    long long n,m;
    cin>>n>>m;

    vector<long long>x(n);
    for(long long i=0;i<n;i++)
    cin>>x[i];
    
    vector<long long>r(n);

    for(long long i=0;i<n;i++)
    cin>>r[i];


    map<long long,long long>mp;

    for(long long i=0;i<n;i++)
    {

        for(long long j=(x[i]-r[i]);j<=(x[i]+r[i]);j++)
        {
            long long y=(r[i]*r[i])-((j-x[i])*(j-x[i]));
            if(mp.find(j)==mp.end())
            mp[j]=y;
            else
            mp[j]=max(mp[j],y);
        }
    }

    long long count=0;
    for(auto it:mp)
    {
        long long yy=sqrt(it.second);

        long long d=(2*yy)+1;
        count+=d;
    }
    cout<<count<<endl;
}