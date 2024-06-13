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
    long long n;
    cin>>n;
         string s=to_string(n);
        
        long long m=s.length();
        vector<vector<vector<long long>>>dp(m+1,vector<vector<long long>>(3,vector<long long>(3,-1)));
        function<long long(long long,long long,long long)>f=[&](long long i,long long tight,long long flag)->long long{
         
         
          if(i==m)
          {
              return flag;
          }
           
           if(dp[i][tight][flag]!=-1)
           return dp[i][tight][flag];
           long long low=0;
           
           long long high=(tight==1)?(s[i]-'0'):9;
           long long res=0;
           for(long long j=low;j<=high;j++)
           {
               long long newFlag=flag;
               if(j==4)
               newFlag=1;
               
               long long newTight=0;
               if(tight==1 && j==high)
               newTight=1;
               
               res+=f(i+1,newTight,newFlag);
               
           }
           
           return dp[i][tight][flag]= res;
        };
        
        long long res=f(0,1,0);
        cout<<res<<endl;
}