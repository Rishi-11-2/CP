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
    cout.precision(12);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
double dist(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2));
}
void solve()
{
    int n,s,t;
    cin>>n>>s>>t;
    vector<vector<int>>points;
    double ss=(double)(s);
    double tt=(double)(t);
    for(int i=1;i<=n;i++)
    {
        int a,b,x,y;
        cin>>a>>b>>x>>y;

        points.push_back({a,b,x,y});
    }
    int limit=(1LL<<n)-1;
    function<double(int,int,int)>f=[&](int mask,int i,int j)->double{
        // debug(mask);
        if(mask==limit)
        {
            return (double)(0);
        }

        double res=(1e9);

        for(int k=0;k<n;k++)
        {
            if(mask&(1LL<<k))
            continue;

            int a=points[k][0];
            int b=points[k][1];
            int c=points[k][2];
            int d=points[k][3];

            double dab=dist(i,j,a,b);
            double dcd=dist(i,j,c,d);
            double dabcd=dist(a,b,c,d);

            dab=(dab/ss);
            dcd=(dcd/ss);
            dabcd=(dabcd/tt);
            res=min(res,dab+dabcd+f(mask|(1LL<<k),c,d));
            res=min(res,dcd+dabcd+f(mask|(1LL<<k),a,b));

        }

        return res;        
    };

    double res=f(0,0,0);

    cout<<res<<endl;
}