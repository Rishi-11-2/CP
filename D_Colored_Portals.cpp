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
    long long n,q;
    cin>>n>>q;

    vector<string>v;

    for(long long i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }

    vector<vector<long long>>prefix(n+2,vector<long long>(20,-1));
    vector<vector<long long>>suffix(n+2,vector<long long>(20,-1));

    map<char,long long>mp;
    mp['B']=0;
    mp['G']=1;
    mp['R']=2;
    mp['Y']=3;
    for(long long i=1;i<=n;i++)
    {
        string a=v[i-1];
        long long mask=(1LL<<mp[a[0]])|(1LL<<mp[a[1]]);
        prefix[i]=prefix[i-1];

        prefix[i][mask]=i;
    }
     
    for(long long i=n;i>=1;i--)
    {
        string a=v[i-1];
        long long mask=(1LL<<mp[a[0]])|(1LL<<mp[a[1]]);
        suffix[i]=suffix[i+1];

        suffix[i][mask]=i;   
    }

    for(long long i=1;i<=q;i++)
    {
        long long l,r;
        cin>>l>>r;

        string a=v[l-1];
        string b=v[r-1];

        long long mask1=(1LL<<mp[a[0]])|(1LL<<mp[a[1]]);   

        long long mask2=(1LL<<mp[b[0]])|(1LL<<mp[b[1]]);

        long long d=mask1&mask2;
        // debug("hello");
        if(d>0)
        {
            cout<<abs(r-l)<<endl;
            continue;
        }

        vector<long long>vx;
        vector<long long>vy;
        vx.push_back(mp[a[0]]);
        vx.push_back(mp[a[1]]);
        vy.push_back(mp[b[0]]);
        vy.push_back(mp[b[1]]);
        long long res=(long long )(1e18);
        for(long long k1 =0;k1<2;k1++)
        {
            for(long long k2=0;k2<2;k2++)
            {
                long long mmask=(1<<vx[k1])|(1<<vy[k2]);
                // debug(mmask,abs(l-prefix[l-1][mmask])+abs(r-prefix[l-1][mmask]),abs(l-suffix[l+1][mmask])+abs(r-suffix[l+1][mmask]));
                if(prefix[l-1][mmask]!=-1)
                {
                    res=min(res,abs(l-prefix[l-1][mmask])+abs(r-prefix[l-1][mmask]));
                }
               if(suffix[l+1][mmask]!=-1)
                {
                    res=min(res,abs(l-suffix[l+1][mmask])+abs(r-suffix[l+1][mmask]));
                }
            }
        }

        if(res==(long long)(1e18))
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<res<<endl;
        }
    }

}