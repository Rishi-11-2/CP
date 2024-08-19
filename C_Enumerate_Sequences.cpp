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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
set<vector<long long>>s;
void f(long long i,vector<long long>&v,vector<long long>&r,long long sum,long long k)
{
    if(i==(long long)r.size())
    {
        // debug((long long)v.size());
        if(sum%k==0)
        {
            s.insert(v);

        }
        return ;
    }
    // debug(i);
    for(long long j=1;j<=r[i];j++)
    {
        long long new_sum=sum+j;
        v.push_back(j);
        f(i+1,v,r,new_sum,k);
        v.pop_back();
    }
}
void solve()
{
    long long n,k;
    cin>>n>>k;

    vector<long long>r;

    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        r.push_back(x);
    }
    // debug);
    vector<long long>v;
    f(0,v,r,0,k);

    for(auto it:s)
    {
        for(auto i:it)
        cout<<i<<" ";
        cout<<endl;
    }

}