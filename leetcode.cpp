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
    int n;
    cin>>n;

    vector<vector<int>>requirements(n+1,vector<int>(2,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        cin>>requirements[i][j];
    }
    
            sort(requirements.begin(),requirements.end());
        vector<vector<int>>dp(n+1,vector<int>(500,-1));
        function<int(int,int)>f=[&](int i,int prev)->int{
         
                         
            if(i>=n)
                return 1;
            
            if(prev>requirements[i][1])
                return 0;

            int res=0;
            if(dp[i][prev]!=-1)
                return dp[i][prev];
            if(i==requirements[i][0])
            {
                return dp[i][prev]= f(i+1,requirements[i][1]);
            }
            for(int j=prev;j<=400;j++)
            {
                res+=f(i+1,j);
            }
            
            return dp[i][prev]= res;
            
        };
        
        int res=f(0,0);

        cout<<res<<endl;
}