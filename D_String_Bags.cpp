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
    string s;
    cin>>s;
    long long n=s.length();
    long long m;
    cin>>m;
    map<long long,vector<string>>mp;
    for(long long i=0;i<m;i++)
    {
        long long len;
        cin>>len;
        for(long long j=1;j<=len;j++)
        {
            string x;
            cin>>x;
            mp[i].push_back(x);
        }
        // for(auto it:mp[len])
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
    }
    vector<vector<long long>>dp(m+5,vector<long long>(n+5,-1));
    function<long long(long long ,long long)>f=[&](long long p, long long i)->long long{

        if(p==m)
        {
            if(i==n)
            return 0;

            return (long long)(1e10);
        }
        if(dp[p][i]!=-1)
        return dp[p][i];
        long long res=f(p+1,i);
        long long sz=(long long)(mp[p].size());
        for(long long j=0;j<sz;j++)
        {
            long long c=i;
            long long flag=1;
            // debug(j);
            for(long long k=0;k<mp[p][j].length();k++)
            {
                // debug(mp[p][j][k],c,p);
                if(s[c]==mp[p][j][k])
                {
                    c++;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                // debug(p,c);
                res=min(res,1+f(p+1,c));
            }
        }

        return dp[p][i]=  res;
    };


    long long x=f(0,0);

    if(x==(long long)(1e10))
    {
        cout<<-1<<endl;
        return;
    }
    cout<<x<<endl;

}