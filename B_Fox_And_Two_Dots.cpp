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
    long long n,m;
    cin>>n>>m;

    vector<vector<char>>grid(n+1,vector<char>(m+1));

    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<long long>>vis(n+1,vector<long long>(m+1,0)); 

    long long res=0;
    long long si=-1;
    long long sj=-1;
    function<void(long long,long long,long long,char)>f=[&](long long i ,long long j,long long count,char c)->void{

        long long a[]={-1,1,0,0};
        long long b[]={0,0,-1,1};
        // debug(i,j);
        for(long long k=0;k<4;k++)
        { 
            long long x=a[k]+i;
            long long y=b[k]+j;

            if(x>=0 && y>=0 && x<n && y<m)
            {
                if(vis[x][y]==1 && count>3  && (x==si && y==sj))
                {
                    // debug(i,j,x,y);
                    res=1;
                    return;
                }
                if(!vis[x][y] && grid[x][y]==c)
                {
                    vis[x][y]=1;
                    f(x,y,count+1,c);
                }
            }
        }
    };
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            if(!vis[i][j])
            {
                vis= vector<vector<long long>>(n+1,vector<long long>(m+1,0));
                vis[i][j]=1;
                si=i;
                sj=j;
                // debug(grid[i][j]);
                f(i,j,1,grid[i][j]);

                if(res==1)
                {
                    cout<<"Yes"<<endl;
                    return;
                }
            }
        }
    }

    cout<<"No"<<endl;
    
}