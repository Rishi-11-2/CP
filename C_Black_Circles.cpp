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
    cout.precision(15);
    long long  t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

void solve()
{
    long long  n;
    cin>>n;

    vector<pair<long long,long long>>v;
    for(long long  i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    long long x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    long long a,b,c;
    // getLine(x1,y1,x2,y2,a,b,c);
    function<long long(long long,long long,long long,long long)>f=[&](long long x1,long long y1,long long x2,long long y2)->long long{
        long long d=((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        // d=sqrtl(d);
        return d;
    };
    
    long long d=f(x1,y1,x2,y2);
    for(long long i=0;i<n;i++)
    {
        long long d1=f(x1,y1,v[i].first,v[i].second);
        long long d2=f(x2,y2,v[i].first,v[i].second);
        // debug(d1,d2,d,max(d1,d2));
        // debug(d2,d);
        if(d2<=d)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}