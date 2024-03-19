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
    long long v1,v2,v3;
    cin>>v1>>v2>>v3;
    
    long long a1,b1,c1;
    a1=0;
    b1=0;
    c1=0;
    function<long long(long long,long long,long long,long long,long long,long long,long long,long long,long long)>f=[&](long long a1,long long a2,long long a3,long long b1,long long b2,long long b3,long long c1,long long c2,long long c3)->long long{

        long long x=max(0LL,(min({a1,a2,a3})+7)-max({a1,a2,a3}));
        long long y=max(0LL,(min({b1,b2,b3})+7)-max({b1,b2,b3}));
        long long z=max(0LL,(min({c1,c2,c3})+7)-max({c1,c2,c3}));

        return x*y*z;
    };
     function<long long(long long,long long,long long,long long,long long,long long)>f1=[&](long long a1,long long a2,long long b1,long long b2,long long c1,long long c2)->long long{

        long long x=max(0LL,(min({a1,a2})+7)-max({a1,a2}));
        long long y=max(0LL,(min({b1,b2})+7)-max({b1,b2}));
        long long z=max(0LL,(min({c1,c2})+7)-max({c1,c2}));

        return x*y*z;
    };
    for(long long a2=-7;a2<=7;a2++)
    {
        for(long long b2=-7;b2<=7;b2++)
        {
            for(long long c2=-7;c2<=7;c2++)
            {
                for(long long a3=-7;a3<=7;a3++)
                {
                    for(long long b3=-7;b3<=7;b3++)
                    {
                        for(long long c3=-7;c3<=7;c3++)
                        {
                            long long tv3=f(a1,a2,a3,b1,b2,b3,c1,c2,c3);
                            long long tv12=f1(a1,a2,b1,b2,c1,c2);
                            long long tv23=f1(a2,a3,b2,b3,c2,c3);
                            long long tv13=f1(a1,a3,b1,b3,c1,c3);

                            long long tv2=(tv12+tv13+tv23)-3*tv3;

                            long long tv1=3*7*7*7-2*tv2-3*tv3;

                            if(tv1==v1 && tv2==v2 && tv3==v3)
                            {
                                cout<<"Yes"<<endl;
                                cout<<a1<<" "<<b1<<" "<<c1<<" "<<a2<<" "<<b2<<" "<<c2<<" "<<a3<<" "<<b3<<" "<<c3<<endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }


    cout<<"No"<<endl;
}