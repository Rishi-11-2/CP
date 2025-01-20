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
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>>grid(n,vector<int>(m));

    vector<int>rs(n,0);
    vector<int>cs(m,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            rs[i]+=grid[i][j];
            col[j]+=grid[i][j];
        }
    }

    string s;
    cin>>s;
    vector<int>row(n,0);
    vector<int>col(m,0);
    int idx=0;
    function<void(int,int)>f=[&](int i,int j)->void{

        row[i]++;
        col[j]++;

        if(i==n-1 && j==m-1)
        {
            break;
        }
        char c=s[idx++];
        if(c=='D')
        {
            f(i+1,j);
        }
        else
        {
            f(i,j+1);
        }
    };
    f(0,0);

    idx=0;

    function<void(int,int)>f1=[&](int i,int j)->void{
        
        mp1[row[i]].insert({i,j});
        mp1[col[j]].insert({i,j});

        if(i==n-1 && j==m-1)
        {
            break;
        }
        char c=s[idx++];
        if(c=='D')
        {
            f1(i+1,j);
        }
        else
        {
            f1(i,j+1);
        }
    };
    f1(0,0);

    queue<pair<int,int>>q;
    for(int i=0;i<n;i++)
    {
        if(row[i]==1)
        {
            for(auto it:mp1[i])
            {
                int i=it.first;
                int j=it.second;
                if(vis[i][j]==0)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
            mp1[i].clear();
            mp1.erase(i);
        }
    }
    for(int i=0;i<m;i++)
    {
        if(col[i]==1)
        {
            for(auto it:mp2[i])
            {
                int i=it.first;
                int j=it.second;
                if(vis[i][j]==0)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
            mp2[i].clear();
            mp2.erase(i);
        }
    }
    vector<vector<int>>vis(n+1,vector<int>(m+1,0));
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int i=it.first;
        int j=it.second;

        if(vis[i][j])
        continue;
        
        if(row[i]==1)
        {
            grid[i][j]=-rs[i];
            rs[i]=0;
            cs[j]+=grid[i][j];
        }
        else{
            grid[i][j]=-cs[j];
            cs[j]=0;
            rs[i]+=grid[i][j];
        }

        row[i]--;
        col[j]--;

    }
    

}