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
    long long n,k;
    cin>>n>>k;
    vector<long long>d(11,0);
    d[1]=0;
    d[2]=1;
    /*https://medium.com/@harshittheone007/counting-derangements-b97ae9ec4582*/
    for(long long i=3;i<=10;i++)
    {
        d[i]=(i-1)*(d[i-1]+d[i-2]);
    }
    vector<vector<long long>>c(n+1,vector<long long>(k+1,0));

    for(long long i=0;i<=n;i++)
    {
        for(long long j=0;j<=min(i,k);j++)
        {
            if(i==0||j==0)
            {
                c[i][j]=1;
                continue;
            }
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }

    long long res=0;
    for(long long i=0;i<=k;i++)
    {
        // debug(i,d[i],c[n][i]);
        res=(res+d[i]*c[n][i]);

    }
    cout<<res+1<<endl;

}