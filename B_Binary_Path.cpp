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
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin>>n;
    vector<vector<char>>s(2,vector<char>(n));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>s[i][j];
        }
    }
    string x="";
    int idx=n-1;

    for(int i=n-1;i>=1;i--)
    {
        if(s[0][i]=='1' && s[1][i-1]=='0')
        {
            idx=i-1;
            // break;
        }
    }
    // debug(idx);
    for(int j=0;j<=idx;j++)
    {
        x+=s[0][j];
    }
    for(int j=idx;j<n;j++)
    {
        x+=s[1][j];
    }
    cout<<x<<endl;
    int count=0;
    vector<vector<vector<int>>>dp(n+2,vector<vector<int>>(3,vector<int>(3,-1)));
    function<int(int,int,int)>f=[&](int i,int j,int flag)->int{
        if(i>(n))
        return 0;
        if(i==n)
        {
            
            // debug(i,j,flag);
            if(flag==1)
            {
                // count++;
                return 1;
            }
            
            return 0;
        }
        int res=0;

        if(dp[i][j][flag]!=-1)
        return dp[i][j][flag];
        // debug(i,j,flag);
        if(s[j][i]==x[i+flag])
        {
            res+=f(i+1,j,flag);
        }
        if(flag == 0 && i+1<(n+1) && (s[1-j][i]==x[i+1]) && (s[j][i]==x[i]))
        {
            // debug(i,j,flag);
            res+=f(i+1,1-j,1);
        }
        return dp[i][j][flag]= res;
    };

    int ans=f(0,0,0);

    cout<<ans<<endl;
}