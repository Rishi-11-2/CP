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
    long long l,r,g;
    cin>>l>>r>>g;

    long long d1=(l/g);

    d1=d1*g;

    while(d1<l)
    {
        d1+=g;
    }

    long long d2=(r/g);

    d2=d2*g;

    while((d2+g)<=r)
    {
        d2+=g;
    }

    

    long long diff=(d2-d1);



    for(long long i=(diff/g);i>=0;i--)
    {
        for(long long j=(d1/g);(j+i)<=(d2/g);j++)
        {
            if(__gcd(j,j+i)==1)
            {
                cout<<j*g<<" "<<(j+i)*g<<endl;
                return;
            }
        }
    }

        
    cout<<-1<<" "<<-1<<endl;
}