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
 vector<vector<long long>>mul(vector<vector<long long>>res,vector<vector<long long>>mat,int m)
    {
        // for(auto it:res)
        // {
        //   for(auto i:it)
        //   cout<<i<<" ";
        //   cout<<"LU"<<endl;
        // }
        // cout<<"LV"<<endl;
        int n1=res.size();
        int n2=res[0].size();
        int n3=mat[0].size();
        debug(n1,n2,n3);
        vector<vector<long long>>v(n1,vector<long long>(n3,0));
       for(int i=0;i<n1;i++)
       {
           for(int j=0;j<n3;j++)
           {
                long long s=0;
               for(int k=0;k<n2;k++)
               {
                   s=((res[i][k]%m*mat[k][j]%m)%m+s)%m;
                   if(n1!=n3)
                   {
                    debug(res[i][k],mat[k][j],i,j,k);
                   }
               }
              
               v[i][j]=s;
           }
       }

       for(auto it:v)
       {
          for(auto i:it)
          cout<<i<<" ";
          cout<<endl;
       }
       cout<<"OK"<<endl;
       return v;
    }
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        // code here
        
        vector<vector<long long>>mat={{a,b,1},{1,0,0},{0,0,1}};
        vector<vector<long long>>res={{1,0,0},{0,1,0},{0,0,1}};
        vector<vector<long long>>res1;
        vector<long long>x;
        x.push_back(1);
        res1.push_back(x);
        res1.push_back(x);

        x.pop_back();
        x.push_back(c);

        res1.push_back(x);
        
        
        if(n<=2)
        {
            return 1LL;
        }
        
        n-=2;
        
        while(n>0)
        {
            if(n&1)
            {
                res=mul(res,mat,m);
            }
            mat=mul(mat,mat,m);
            n>>=1LL;
        }
        res=mul(res,res1,m);
        return res[0][0];
    }
void solve()
{
  long long a,b,c,n,m;
  cin>>a>>b>>c>>n>>m;

  cout<<genFibNum(a,b,c,n,m);
}