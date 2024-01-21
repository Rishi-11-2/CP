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
    int n;
    cin>>n;
    int y=1;
    int z=2;
    while(z<n)
    {
        z=z*2;
        y++;
    }
    cout<<y<<endl;
    vector<vector<int>>v(y+1);
    for(int i=1;i<=n;i++)
    {
       for(int j=1;j<=y;j++)
       {
          int j1=j-1;
          int i1=i-1;
          if((i1&(1<<j1)))
          {
            v[j].push_back(i);
          }
       }
    }
    for(int i=1;i<=y;i++)
    {
        cout<<(int)(v[i].size())<<" ";
        for(int j=0;j<(int)(v[i].size());j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    string s;
    cin>>s;
    // reverse(all(s));

    int i=0;
    int res=0;
    for(char c:s)
    {
        int x=(c-'0');
        if(x==1)
        res+=(1<<i);
        i++;
    }
    cout<<res+1<<endl;
    
}