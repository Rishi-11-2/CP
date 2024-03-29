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
vector<long long>c((long long)(1e6+1),0);
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
    // c.assign((long long)(1e6),0);
    long long arr[n];
    set<long long>s;
    long long maxm=0;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        c[arr[i]]++;
        maxm=max(maxm,arr[i]);
        s.insert(arr[i]);
    }
    vector<long long>v(all(s));
    long long m=v.size();
    long long res=0;
    for(long long i=0;i<m;i++)
    {
        long long y=maxm;
        res+=(c[v[i]])*(c[v[i]]-1)*(c[v[i]]-2);
        // debug(c[v[i]]);
        for(long long j=2;v[i]*j*j<=y;j++)
        {
                // debug(v[i],v[i]*j,v[i]*j*j,c[v[i]],c[v[i]*j],c[v[i]*j*j],res);
                res+=(c[v[i]*j])*(c[v[i]*j*j])*c[v[i]];
        }
    }
    // c.clear();
    for(int i=0;i<n;i++)
    c[arr[i]]=0;
    cout<<res<<endl;
}