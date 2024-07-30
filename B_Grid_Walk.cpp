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
    int n,m;
    cin>>n>>m;
    int i,j;
    cin>>i>>j;
    vector<vector<char>>grid(n,vector<char>(m,'/'));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>grid[i][j];
    }
    string s;
    cin>>s;
    i--;
    j--;
    int k=0;
    map<char,int>mp;
    mp['U']=0;
    mp['D']=1;
    mp['L']=2;
    mp['R']=3;
    int a[]={-1,1,0,0};
    int b[]={0,0,-1,1};
    while(k<s.length())
    {
        char c=s[k];
        int idx=mp[c];
        int x=i+a[idx];
        int y=j+b[idx];
        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]=='.')
        {
            i=x;
            j=y;
        }
        k++;
    }

    cout<<i+1<<" "<<j+1<<endl;

}