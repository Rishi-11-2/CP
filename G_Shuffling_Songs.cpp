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
    vector<pair<string ,string>>v;
    for(int i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    vector<vector<int>>dp((1<<n),vector<int>(n,-1));
    vector<vector<int>>ok(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                ok[i][j]=1;
                continue;
            }
            if(v[i].first==v[j].first||v[i].second==v[j].second)
            {
                ok[i][j]=1;
            }
        }
    }
    sort(all(v));

    function<int(int ,int)>f=[&](int i,int mask)->int{

        if(dp[mask][i]!=-1)
        return dp[mask][i];
        int res=__builtin_popcount(mask);

        for(int j=0;j<n;j++)
        {
            if((mask&(1<<j))!=0)
            continue;
            if(ok[i][j])
            {
                int newMask=mask|(1<<j);
                res=max(res,f(j,newMask));
            }
        }
        return dp[mask][i]= res;
    };
    int res=0;
    for(int i=0;i<n;i++)
    {
        int mask=1<<i;
        res=max(res,f(i,mask));
    }

    cout<<n-res<<endl;
}