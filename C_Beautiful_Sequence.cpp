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
    long long n;
    cin>>n;

    long long arr[n];

    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    std::vector<std::vector<std::vector<std::vector<long long>>>> dp(n, 
        std::vector<std::vector<std::vector<long long>>>(3, 
            std::vector<std::vector<long long>>(3, 
                std::vector<long long>(3, -1) 
            )
        )
    );
    const long long mod=(long long)998244353;
    function<long long(long long,long long,long long,long long)>f=[&](long long i,long long flag1,long long flag2,long long flag3)->long long{
        
        if(flag3==1  && flag1==1)
        return 1;
        if(i==n)
        {

            return 0;
        }
        if(dp[i][flag1][flag2][flag3]!=-1)
        return dp[i][flag1][flag2][flag3];
        long long res=f(i+1,flag1,flag2,flag3);
        if(arr[i]==1)
        {
            if(flag1==0 && flag2==0 && flag3==0)
            res=(res%mod+f(i+1,1,0,0)%mod)%mod;
        }
        if(arr[i]==2)
        {
            if(flag1==1 && flag3==0)
            {
                res=(res%mod+f(i+1,1,1,0)%mod)%mod;
            }
        }
        if(arr[i]==3)
        {
            if(flag1==1 && flag2==1)
            res=(res%mod+f(i+1,1,1,1)%mod)%mod;
        }

        return dp[i][flag1][flag2][flag3]= res;

    };

    long long ans=f(0,0,0,0);
    cout<<ans<<endl;


}