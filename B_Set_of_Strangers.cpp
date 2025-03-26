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
    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n,m;
    cin>>n>>m;

    long long arr[n][m];

    set<long long>s1;
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            cin>>arr[i][j];
            s1.insert(arr[i][j]);
        }
    }

    set<long long>s2;

    long long a[]={-1,1,0,0};
    long long b[]={0,0,-1,1};
    
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            long long c=0;
            for(long long k=0;k<4;k++)
            {
                long long x=a[k]+i;
                long long y=b[k]+j;
                if(x>=0 && y>=0 && x<n && y<m && arr[x][y]==arr[i][j])
                {
                    c++;
                }
            }
            if(c>0)
            {
                s2.insert(arr[i][j]);
            }
        }
    }
        
    long long ans=(long long)s1.size();

    ans--;

    long long d=(long long )s2.size();

    if(d>0)
    {
        ans+=d;
        ans--;
    }

    cout<<ans<<endl;
}