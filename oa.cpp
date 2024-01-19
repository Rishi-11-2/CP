#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
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
    int n,k;
    cin>>n>>k;
    double p;
    cin>>p;
    function<double(int ,int )>f=[&](int i,int flag)->double{

        if(i==n)
        {
            if(flag==1)
            return 1;
            
            return 0;
        }
        int minm=k;
        if(flag==1)
        {
            minm=1;
        }
        int res=f(i+1,flag);
        double product=1;
        for(int j=1;j<=k;j++)
        {
            product=product*p;
        }
        for(int j=i+minm;j<n;j++)
        {
            res+=f(j,1)*product;
            product*=p;
        }
        return res;
    };
    double x=f(0,0);
    cout<<x<<endl;
}