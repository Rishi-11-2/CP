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
    long long n;
    cin>>n;

    vector<string>vv;
    vector<pair<long long,long long>>vx;
    for(long long i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        vv.push_back(s);
        for(long long j=0;j<n;j++)
        {
            if(s[j]=='P')
            vx.push_back({i-1,j});
        }
    }
    set<vector<long long>>vis;
    long long res=INT_MAX;
    function<long long(long long,long long,long long,long long,long long)>f=[&](long long x1,long long y1,long long x2,long long y2,long long d)->long long{
        debug(x1,y1,x2,y2);
        vis.insert({x1,y1,x2,y2,d});
        if(x1==x2 && y1==y2)
        {
            res=min(res,d);
        }
        // if(x1<0||x2<0||x1>n-1||x2>n-1||y1<0||y2<0||y1>n-1||y2>n-1)
        // return (long long)(1e9);

        long long a[]={-1,1,0,0};
        long long b[]={0,0,-1,1};
        
        long long res=(long long)(1e9);
        for(long long k=0;k<4;k++)
        {
            long long  x11=x1+a[k];
            long long  y11=y1+b[k];
            long long  x22=x2+a[k];
            long long  y22=y2+b[k];
            if(x11<0||y11<0||y11>n-1||x11>n-1)
            {
                x11=x1;
                y11=y1;
            }
            if(x22<0||y22<0||y22>n-1||x22>n-1)
            {
                x22=x2;
                y22=y2;
            }
            if(vv[x11][y11]=='#')
            {
                x11=x1;
                y11=y1;
            }
            if(vv[x22][y22]=='#')
            {
                x22=x2;
                y22=y2;
            }
            vector<long long>v;
            v.push_back(x11);
            v.push_back(y11);
            v.push_back(x22);
            v.push_back(y22);
            v.push_back(d+1);
            if(vis.find(v)==vis.end())
            {
                vis.insert(v);
                res=min(res,1+f(x11,y11,x22,y22,d+1));
            }
        }

        return res;
    };
    cout<<vx[0].first<<" "<<vx[0].second<<" "<<vx[1].first<<" "<<vx[1].second<<endl;
    long long x=f(vx[0].first,vx[0].second,vx[1].first,vx[1].second,0);

    if(x==(long long)(1e9))
    cout<<-1<<endl;
    else
    cout<<x<<endl;
}