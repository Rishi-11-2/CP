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
    long long a,b,c,x,y,z,k;

    cin>>a>>b>>c>>x>>y>>z>>k;

    vector<long long>v;

    v.push_back(abs(x-a));

    v.push_back(abs(y-b));
    
    v.push_back(abs(z-c));

    sort(all(v));

    long long ans=0;


    if((v[0]*k)<=v[2])
    {
        ans+=v[0];
        ans+=k*v[0];
        v[2]-=v[0]*k;

        if((v[1]*k)<=v[2])
        {
            ans+=v[1];
            ans+=k*v[1];
            v[2]-=v[1]*k;

            if(v[2]>0)
            {
                ans+=v[2];
                long long x=((v[2]+k-1)/k);
                if(x%2)
                x--;

                ans+=x;
            }
        }
        else{
            ans+=v[2]+v[1];
        }
    }
    else
    {
        ans+=v[0]+v[1]+v[2];
    }

    cout<<ans<<endl;


}