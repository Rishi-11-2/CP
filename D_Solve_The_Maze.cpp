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
//(data type to be stored (pair,long long ,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong long s)
typedef tree < pair<long long ,long long >, null_type,less<pair<long long ,long long >>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long  t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long  n,m;
    cin>>n>>m;

    char  grid[n][m];

    vector<pair<long long ,long long >>good; 
    vector<vector<long long >>vis(n+1,vector<long long >(m+1,0));
    for(long long  i=0;i<n;i++)
    {
        for(long long  j=0;j<m;j++)
        cin>>grid[i][j];
    }
    for(long long  i=0;i<n;i++)
    {
        for(long long  j=0;j<m;j++)
        {
            // cin>>grid[i][j];
            if (grid[i][j]=='G')
            {
                good.push_back({i,j});
                // dis[i][j]=0;
            }
            else if(grid[i][j]=='B')
            {

                long long  a[]={-1,1,0,0};
                long long  b[]={0,0,-1,1};

                for(long long  k=0;k<4;k++)
                {
                    long long  x=a[k]+i;
                    long long  y=b[k]+j;
                    if(x>=0 && y>=0 && x<n && y<m)
                    {
                        // debug(x,y,i,j);
                        if(grid[x][y]=='G')
                        {
                            cout<<"No"<<endl;
                            return;
                        }
                        if(grid[x][y]=='.')
                        grid[x][y]='#';
                    }
                }
            }
        }
    }

    queue<pair<long long ,long long >>q;

    q.push({n-1,m-1});

    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        long long  i=it.first;
        long long  j=it.second;
        if(grid[i][j]=='#')
        continue;
        // debug(i,j,grid[i][j]);
        long long  a[]={-1,1,0,0};
        long long  b[]={0,0,-1,1};
        vis[i][j]=1;
        for(long long  k=0;k<4;k++)
        {
            long long  x=a[k]+i;
            long long  y=b[k]+j;
            if(x>=0 && y>=0 && x<n && y<m)
            {
                if(grid[x][y]!='#' && !vis[x][y])
                {
                    vis[x][y]=1;
                    q.push({x,y});
                }
            }
        }
        
    }

    for(auto it:good)
    {
        if(vis[it.first][it.second]==0)
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;



}