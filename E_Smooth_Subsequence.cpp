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
    int n,d;
    cin>>n>>d;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];


    vector<int>dp(n+1,-1);
    function<int(int)>f=[&](int i)->int{
        if(i==n)
        return 0;
       
        if(dp[i]!=-1)
        return dp[i];
        int res=0;
        res+=f(i+1);
        for(int j=i+1;j<n;j++)
        {
            if(abs(a[i]-a[j])<=d)
            res+=1+f(j);
        }
        return dp[i]= res;
    };

    cout<<f(0)<<endl;
}