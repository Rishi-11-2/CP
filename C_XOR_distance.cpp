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
    long long a,b,r;
    cin>>a>>b>>r;

    long long count=0;
    if(b>a)
    swap(a,b);
    long long flag=1;
    for(long long i=61;i>=0;i--)
    {
        long long bita=(a&(1LL<<i))?1:0;
        long long bitb=(b&(1LL<<i))?1:0;
        if(bita==bitb)
        continue;
        long long new_count=(count+(1LL<<i));
        // debug(i,bita,bitb);
        if(!flag && bita && new_count<=r)
        {
            long long c=(1LL<<i);
            a=a^c;
            b=b^c;
            count+=c;
        }
        flag=0;
    }
    // debug(a,b);
    cout<<abs(a-b)<<endl;
}