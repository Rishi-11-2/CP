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
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
class DSU{

    public:
    vector<long long>size;
    vector<long long>parent;

    DSU(long long n)
    {
        size.resize(n+1);
        parent.resize(n+1);
        for(long long i=0;i<=n;i++)
        {
            size[i]=1;
            parent[i]=i;
        }
    }

    long long findUlp(long long node)
    {
        if(node==parent[node])
        return node;

       return parent[node]=findUlp(parent[node]);
    }

    void unionBySize(long long u,long long v)
    {
        long long ulp_u=findUlp(u);
        long long ulp_v=findUlp(v);
        if(ulp_u==ulp_v)
        return;
        
        if(size[ulp_u]>size[ulp_v])
        {
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
        else
        {
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;

        }
    }
};
void solve()
{
    long long n,m;
    cin>>n>>m;

    char grid[n][m];

    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        cin>>grid[i][j];
    }

    DSU d(n*m+10);

    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            if(grid[i][j]=='.')
            continue;
            long long a[]={-1,1,0,0};
            long long b[]={0,0,-1,1};
            for(long long k=0;k<4;k++)
            {
                long long x=i+a[k];
                long long y=j+b[k];
                if(x>=0 && y>=0 && x<n && y<m)
                {
                    if(grid[x][y]=='#')
                    {
                        long long u=m*i+j;
                        long long v=m*x+y;
                        d.unionBySize(u,v);
                    }
                }
            }
        }
    }
    long long res=0;
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            if(grid[i][j]=='#')
            {
                res=max(res,d.size[d.findUlp(m*i+j)]);
            }
        }
    }

    for(long long i=0;i<n;i++)
    {
        set<long long>s;

        long long count=0;
        for(long long j=0;j<m;j++)
        {
            if(grid[i][j]=='.')
            {
                count++;
                long long a[]={-1,1,0,0};
                long long b[]={0,0,-1,1};
                for(long long k=0;k<4;k++)
                {
                    long long x=a[k]+i;
                    long long y=b[k]+j;
                    if(x>=0 && y>=0 && x<n && y<m)
                    {
                        if(grid[x][y]=='#')
                        s.insert(d.findUlp(m*x+y));
                    }
                }
            }
        }
        for(auto it:s)
        {
            count+=d.size[it];

        }
        res=max(res,count);
    }


     for(long long j=0;j<m;j++)
    {
        set<long long>s;

        long long count=0;
        for(long long i=0;i<n;i++)
        {
            if(grid[i][j]=='.')
            {
                count++;
                long long a[]={-1,1,0,0};
                long long b[]={0,0,-1,1};
                for(long long k=0;k<4;k++)
                {
                    long long x=a[k]+i;
                    long long y=b[k]+j;
                    if(x>=0 && y>=0 && x<n && y<m)
                    {
                        if(grid[x][y]=='#')
                        s.insert(d.findUlp(m*x+y));
                    }
                }
            }
        }
        for(auto it:s)
        {
            count+=d.size[it];

        }
        res=max(res,count);
    }


    cout<<res<<endl;
    
}