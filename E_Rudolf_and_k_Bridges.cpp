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
    long long n,m,k,d;
    cin>>n>>m>>k>>d;
    long long a[n+5][m+5];

    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    vector<long long>v;
    for(long long i=1;i<=n;i++)
    {
        long long res=0;
        res=a[i][1]+1+a[i][m]+1;
        long long j=2;

        if((1+d+1)<m)
        {
            while(j<m)
            {
            
                long long ans=(long long)(1e15);
                long long count=0;
                long long idx=1;
                // idx=1;
                while(count<=d && j<m)
                {
                    // debug(j);
                    count++;
                    if((a[i][j]+1)<ans)
                    {

                        ans=a[i][j]+1;
                        idx=j;
                    }
                    j++;
                }
                // debug(i,ans,idx);
                res+=ans;
                j=idx+1;
                if((idx+d+1)>=m)
                break;
            }
        }
        // debug(res,ans,i);
        // res=min(res,ans);
        v.push_back(res);
    }
    // for(auto it:v)
    // cout<<it<<" ";
    // cout<<endl;
    // sort(all(v));
    long long res=0;
    for(long long i=0;i<k;i++)
    {
        res+=v[i];
    }
    for(long long i=k;i<n;i++)
    {
        long long x=res;
        x-=v[i-k];
        x+=v[i];
        res=min(res,x);
    }
    cout<<res<<endl;

}