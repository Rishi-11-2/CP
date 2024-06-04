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
    int n,t;
    cin>>n>>t;

    int a[t+1];

    for(int i=1;i<=t;i++)
    cin>>a[i];
    
    vector<vector<int>>v(n+1,vector<int>(n+1,0));

    vector<int>rows(n+1,0);
    vector<int>cols(n+1,0);
    int x=0;
    int y=0;

    map<int,pair<int,int>>mp;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            v[i][j]=n*(i-1)+j;
            mp[v[i][j]]=make_pair(i,j);
        }
    }

    for(int k=1;k<=t;k++)
    {
        int i=mp[a[k]].first;

        int j=mp[a[k]].second;

        rows[i]++;
        cols[j]++;
        if(i==j)
        x++;

        if(i+j==n+1)
        y++;
        
        if(rows[i]==n||cols[j]==n || x==n || y==n)
        {
            cout<<k<<endl;
            return;
        }
        
    }
    cout<<-1<<endl;

    
}