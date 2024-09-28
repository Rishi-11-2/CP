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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;

    long long mg;
    cin>>mg;
    map<pair<long long,long long>,long long>mpG;


    for(long long i=1;i<=mg;i++)
    {
        long long x,y;
        cin>>x>>y;
        auto it=make_pair(min(x,y),max(x,y));
        mpG[it]=1;
    }
    long long mh;
    cin>>mh;
    map<pair<long long,long long>,long long>mpH;
    for(long long i=1;i<=mh;i++)
    {
        long long a,b;
        cin>>a>>b;
        auto it=make_pair(min(a,b),max(a,b));
        mpH[it]=1;
    }

   
    vector<vector<long long>>cost(n+1,vector<long long>(n+1,0));

    for(long long i=1;i<=n;i++){
        

        for(long long j=i+1;j<=(n);j++)
        {
            long long x;
            cin>>x;
            cost[i][j]=x;
        }

    }

    long long ans=0;
    for(long long i=1;i<=n;i++)
    {
        long long count1=0;
        long long count2=0;
        set<long long>ss1;
        for(long long j=i+1;j<=n;j++)
        {
            if(mpG[{i,j}])
            count1++;

            if(mpH[{i,j}])
            {
                count2++;
                ss1.insert(cost[i][j]);
            }
        }

        for(long long j=1;j<=abs(count1-count2);j++)
        {
            ans+=*ss1.begin();
            ss1.erase(ss1.begin());
        }
    }

    cout<<ans<<endl;


}