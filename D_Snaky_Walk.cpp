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
    long long  t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{

    long long  n,m;
    cin>>n>>m;

    char grid[n][m];

    pair<long long ,long long >start;
    pair<long long ,long long >end;
    for(long long  i=0;i<n;i++)
    {
        for(long long  j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='S')
            {
                start.first=i;
                start.second=j;
            }
            if(grid[i][j]=='G')
            {
                end.first=i;
                end.second=j;
            }

        }
    }

    priority_queue<vector<long long >,vector<vector<long long >>, greater<vector<long long >>>pq;
    pq.push({0,0,start.first,start.second});
    pq.push({0,1,start.first,start.second});

    long long  dp[n+1][m+1][2];

    for(long long  i=0;i<n;i++)
    {
        for(long long  j=0;j<m;j++)
        {
            for(long long  k=0;k<2;k++)
            {
                dp[i][j][k]=(long long )(1e18);
            }
        }
    }
    // debug(start.first,start.second);
    dp[start.first][start.second][0]=0;
    dp[start.first][start.second][1]=0;

    long long  h1[]={-1,1};
    long long  h2[]={0,0};

    long long  v1[]={0,0};
    long long  v2[]={-1,1};
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();

        long long  d=it[0];
        long long  flag=it[1];
        long long  i=it[2];
        long long  j=it[3];

        // if(i==end.first )
        // debug(i,j,flag);
        if(flag==0)
        {
            for(long long  k=0;k<2;k++)
            {
                long long  x=i+v1[k];
                long long  y=j+v2[k];
                if(x>=0 && y>=0 && x<n && y<m && grid[x][y]!='#')
                {
                    if(dp[x][y][1]>(d+1))
                    {
                        dp[x][y][1]=d+1;
                        pq.push({dp[x][y][1],1,x,y});
                    }
                }
            }
        }
        else
        {
            for(long long  k=0;k<2;k++)
            {
                long long  x=i+h1[k];
                long long  y=j+h2[k];
                if(x>=0 && y>=0 && x<n && y<m && grid[x][y]!='#')
                {
                    if(dp[x][y][0]>(d+1))
                    {
                        dp[x][y][0]=d+1;
                        pq.push({dp[x][y][0],0,x,y});
                    }
                }
            }
        }


    }

    long long x=min(dp[end.first][end.second][0],dp[end.first][end.second][1]);

    if(x==(long long )(1e18))
    {
        x=-1;
    }
    cout<<x<<endl;
}