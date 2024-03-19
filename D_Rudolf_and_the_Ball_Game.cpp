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
void solve()
{
    long long n,m,x;
    cin>>n>>m>>x;

    vector<pair<long long,char>>v;
    for(long long i=1;i<=m;i++)
    {
        long long a;
        cin>>a;
        char c;
        cin>>c;
        v.push_back({a,c});
    }
    set<long long>s;

    vector<vector<long long>>dp(n+5,vector<long long>(m+5,-1));
    function<long long(long long,long long)>f=[&](long long i,long long j)->long long{
        if(j==m)
        {
            s.insert(i);
            return 1;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        long long d=v[j].first;
        char c=v[j].second;
        long long c_new_i=(i+d);
        if(c_new_i>n)
        {
            c_new_i-=n;
        }
        long long ac_new_i=((i+n)-d);
        if(ac_new_i>n)
        ac_new_i-=n;
        // debug(c_new_i,ac_new_i);
        long long res=0;
        if(c=='0')
        {
            res+=f(c_new_i,j+1);
        }
        else if(c=='1')
        {
            res+=f(ac_new_i,j+1);
        }
        else
        {
            res+=f(c_new_i,j+1);
            res+=f(ac_new_i,j+1);
        }

        return dp[i][j]= res;
    };

    long long res=f(x,0);

    cout<<(long long)(s.size())<<endl;
    for(auto it:s)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}