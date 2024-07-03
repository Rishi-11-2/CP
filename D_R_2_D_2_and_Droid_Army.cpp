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
class SparseTable{
    public:
    vector<vector<long long>>dp;
    long long n;
    vector<long long>lg;
    long long m;
    vector<long long>arr;
    SparseTable(vector<long long>&v)
    {
        arr=v;
        m=25;
        n=(long long)v.size();
        lg.resize(n+1);
        dp.assign(m+1,vector<long long>(n+1,0));
        build();
    }

    void build()
    {
        for(long long i=0;i<n;i++)
        {
            dp[0][i]=arr[i];
        }
        for(long long i=1;i<m;i++)
        {
            for(long long j=0;(j+(1<<(i-1)))<n;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
            }
        }

        lg[1]=0;

        for(long long i=2;i<=n;i++)
        {
            lg[i]=(lg[i/2]+1);
        }
    }

    long long query(long long l,long long r)
    {
        if(l==-1 && r==-1)
        return 0;
        long long len=(r-l+1);

        long long i=lg[len];

        return max(dp[i][l],dp[i][r-(1<<i)+1]);

    }
};
void solve()
{
    long long n,m,k;
    cin>>n>>m>>k;
    
    vector<SparseTable>dps;

    vector<vector<long long>>v(n,vector<long long>(m));

    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        cin>>v[i][j];
    }

    for(long long i=0;i<m;i++)
    {
        vector<long long>x;

        for(long long j=0;j<n;j++)
        x.push_back(v[j][i]);
        SparseTable ss(x);
        dps.push_back(ss);
    }

    function<bool(long long,long long)>check=[&](long long i,long long j)->bool{

        long long x1=0;

        for(long long k=0;k<m;k++)
        {
            x1+=dps[k].query(i,j);
        }
        if(x1<=k)
        return true;
        return false;
    };
    long long i=0;
    long long j=0;
    long long res=0;
    long long left=-1;
    long long right=-1;
    while(j<n)
    {
        while(i<j && !check(i,j))
        {
            i++;
        }
       
        long long len=(j-i+1);
        if(len>res && check(i,j))
        {
            res=len;
            left=i;
            right=j;
        }
        j++;
    }
    // cout<<res<<endl;
    // if(res==0)
    // {
    //     cout<<0<<endl;
    //     return;
    // }
    for(long long i=0;i<m;i++)
    {
        cout<<dps[i].query(left,right)<<" ";
    }

    cout<<endl;

}