#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    long long q,a,b,s1;
    cin>>q>>s1>>a>>b;

    long long x=s1;

    const long long mm=(1LL<<32)-1;

    const long long mod=mm+1;
    bitset<mod>s;
    long long sum=0;
    for(long long i=1;i<=q;i++)
    {
        if(x&1)
        {
            long long y=(x)/2;
            if(s[y]==0)
            {
                sum+=y;
                s[y]=1;  
            }
        }
        else
        {
            long long z=(x)/2;
            if(s[z]==1)
            {
                sum-=z;
                s[z]=0;
            }
        }
        x=((a%mod)*(x%mod)+b)%mod;
    }
    cout<<sum<<endl;
}