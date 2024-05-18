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
    long long r;
    cin>>r;

    long long ans=0;
    for(long long x=0;x<=r;x++)
    {

        long long y1=r*r-(x*x);

        long double y2=sqrt(y1);

        y2=ceil(y2);


        long long y3=(r+1)*(r+1)-(x*x);

        long double y4=sqrt(y3);

        y4=floor(y4);

        long long y5=y2;
        long long y6=y4;
        long long xx=sqrt(y3);
        if(xx*xx==y3)
        {
            y6--;
        }
        // debug(x,y5,y6);
        long long res=abs(y5-y6)+1;
        res=res*2;
        if(x==0)
        {
            ans+=res;
            continue;
        }
        res=res*2;
        if(y5==0)
        res--;

        ans+=res;
        
    }
    cout<<ans-1<<endl;

}