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
    long long n,x,y;
    cin>>n>>x>>y;
    long long a[x];
    for(long long i=0;i<x;i++)
    cin>>a[i];
    
    sort(a,a+x);

    set<long long>s;
    for(long long i=0;i<x;i++)
    s.insert(a[i]);
     
    long long res=x-2;
    for(long long i=0;i<x;i++)
    {
        long long next2=a[i]+2;
        if(next2>n)
        {
            next2=next2-n;
        }
        long long next1=a[i]+1;
        if(next1>n)
        {
            next1=next1-n;
        }
        // debug(next1,next2);

        if(s.find(next2)!=s.end() && s.find(next1)==s.end())
        res++;
    }
    cout<<res<<endl;

}