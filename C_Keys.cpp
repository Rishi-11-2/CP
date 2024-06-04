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
    long long n,m,k;
    cin>>n>>m>>k;


    vector<vector<long long>>v(m+1);
    vector<char>c(m+1,'/');

    for(long long i=0;i<m;i++)
    {
        long long len;
        cin>>len;
        // debug(len);
        v[i].push_back(len);
        for(long long j=1;j<=len;j++)
        {
            long long x;
            cin>>x;
            // debug(x);
            v[i].push_back(x-1);
        }
        cin>>c[i];
        // debug(c[i]);
    }
    long long res=0;
    for(long long mask=0;mask<(1LL<<n);mask++)
    {
        long long mb=__builtin_popcount(mask);

        // if(mb<k)
        // {
        //     continue;
        // }
        long long flag=1;
        for(long long i=0;i<m;i++)
        {
          long long count=0;
          for(long long j=1;j<=v[i][0];j++)
          {
            // debug(v[i][j]);
             if(mask&(1LL<<v[i][j]))
             {
                count++;
             }
          }
          if(count>=k && c[i]=='x')
          {
            flag=0;
          }
          if(count<k && c[i]=='o')
          {
            flag=0;
          }
        }
        // if(flag)
        // debug(mask);
        res+=flag;
    }

    cout<<res<<endl;
}