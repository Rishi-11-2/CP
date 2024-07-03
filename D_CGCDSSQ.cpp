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
    vector<long long>lg;
    vector<long long>arr;
    vector<vector<long long>>dp;
    long long n;
    long long m=20;
    SparseTable(vector<long long>&v)
    {
        arr=v;
        n=(long long)(v.size());
        lg.resize(n+1);
        lg[1]=0;
        for(long long i=2;i<=n;i++)
        {
            lg[i]=(lg[i/2]+1);
        }
        build();
    }

    void build()
    {
        dp.assign(m+1,vector<long long>(n+1,0));

        for(long long i=0;i<n;i++)
        {
            dp[0][i]=arr[i];
        }

        for(long long i=1;i<m;i++)
        {
            for(long long j=0;(j+(1<<(i-1)))<n;j++)
            {
                dp[i][j]=__gcd(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
            }
        }
    }

    long long find(long long l,long long r)
    {
        long long len=r-l+1;

        long long i=lg[len];

        return __gcd(dp[i][l],dp[i][r-(1<<i)+1]);
    }
};
void solve()
{
    long long n;
    cin>>n;

    vector<long long>a(n);

    for(long long i=0;i<n;i++)
    cin>>a[i];

   SparseTable s(a);
    
    long long q;
    cin>>q;
    vector<long long>v;
    for(long long i=0;i<q;i++)
    {
        long long x;
        cin>>x;
        v.push_back(x);
    }
    map<long long,long long>mp;
    for(long long i=0;i<n;i++)
    {
        long long j=i;
        long long g=a[i];
        while(j<n)
        {
            long long low=j;
            long long high =n-1;
            long long res=-1;
            g=s.find(i,low);
            // debug(i,j,g);
            while(low<=high)
            {
                long long mid=(low+high)/2;
                if(s.find(i,mid)>=g)
                {
                    res=mid;
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            // debug(i,j,res,g);
            mp[g]+=(res-j+1);
            j=res+1;
            if(j>=n)
            break;
        }
    }

    for(auto it:v)
    {
        cout<<mp[it]<<endl;
    }


}