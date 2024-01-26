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
    int num1,num2;
    cin>>num1>>num2;
    int m=(int)(1e5);
      vector<bool>isPrime(m+1,1);
      isPrime[0]=isPrime[1]=0;
      for(int i=2;i*i<=m;i++)
      {
          if(isPrime[i])
          {
              for(int j=i*i;j<=m;j+=i)
              {
                  isPrime[j]=0;
              }
          }
      }
      string x=to_string(num1);
      string y=to_string(num2);
       queue<pair<string,int>>q;
      set<string>vis;
      vis.insert(x);
       q.push({x,0});
       int res=INT_MAX;
       while(!q.empty())
       {
           string a=q.front().first;
           int d=q.front().second;
           if(a==y)
           {
               res=min(res,d);
           }
           q.pop();
           
           for(int j=0;j<4;j++)
           {
               for(int k=0;k<=9;k++)
               {
                   if(j==0 && k==0)
                   continue;
                   char c=a[j];
                   a[j]=char(k+'0');
                   if(vis.find(a)!=vis.end())
                   continue;
                   int num=stoi(a);
                   if(isPrime[num])
                   {
                //    cout<<a<<endl;
                      vis.insert(a);
                       q.push({a,d+1});
                   }
                   a[j]=c;
               }
           }
       }

       cout<<res<<endl;
}