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
    long long n,k;
    cin>>n>>k;

    long long ans=0;
    long long count=0;
    long long sum=0;

    
    auto f=[&](auto& f, long long l,long long r)->void{

        long long len=r-l+1;

        if(len<k)
        return;

        long long m=(l+r)/2;
        if(len%2)
        {
            ans+=m*(1+sum);
            count++;

            sum+=(m);
            // debug(len,m);
            f(f,l,m-1);
            // f(m+1,r);
        }
        else
        {
            f(f,l,m);
            // f(m+1,r);
        }
    };

    f(f,1,n);
    debug(count);
    cout<<ans<<endl;
}