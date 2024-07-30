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
    int t;
    // cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
}
    vector<string>res;
    void f(int i,int j,string &s,vector<vector<int>>&mat,vector<vector<int>>&vis)
    {
        int n=(int)mat.size();
        if(i==n-1 && j==n-1)
        {
            res.push_back(s);
            return;
        }
        
        int a[]={-1,1,0,0};
        int b[]={0,0,-1,1};
        map<int,char>mp;
        mp[0]='U';
        mp[1]='D';
        mp[2]='L';
        mp[3]='R';
        for(int k=0;k<4;k++)
        {
            int x=a[k]+i;
            int y=b[k]+j;
            if(x>=0 && y>=0 && x<n && y<n && mat[x][y] && !vis[x][y])
            {
                vis[x][y]=1;
                s+=mp[k];
                f(x,y,s,mat,vis);
                vis[x][y]=0;
                s.pop_back();
            }
        }
    }
void solve()
{
        int n;
        cin>>n;
        vector<vector<int>>mat(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cin>>mat[i][j];
        }
        
        string s;
        vector<vector<int>>vis(n+1,vector<int>(n+1,0));
        f(0,0,s,mat,vis);
}