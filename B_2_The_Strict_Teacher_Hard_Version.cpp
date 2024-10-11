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
    long long n,m,q;
    cin>>n>>m>>q;
    vector<long long>b(m);
    // b.push_back(1);
    for(long long i=0;i<m;i++)
    {
        cin>>b[i];
    }
    vector<pair<long long,long long>>v;
    for(long long i=1;i<=q;i++)
    {
        long long x;
        cin>>x;
        v.push_back({x,i-1});
    }
    sort(all(v));
    sort(all(b));
    vector<long long>res(q);
    long long j=0;
    while(j<q && (v[j].first)<b[0])
    {
        long long pos=v[j].first;
        res[v[j].second]=(b[0]-1);
        j++;
    }
    long long i=1;
    while(j<q && i<m)
    {
        if(v[j].first>b[i])
        {
            i++;
        }
        else if(b[i]>v[j].first)
        {
            long long ans=max((b[i]-b[i-1])/2LL;
            res[v[j].second]=ans;
            j++;
        }
    }
    while(j<q)
    {
        long long pos=v[j].first;
        res[v[j].second]=(n-b[m-1]);
        j++;
    }

    for(long long i=0;i<q;i++)
    cout<<res[i]<<endl;
    
}