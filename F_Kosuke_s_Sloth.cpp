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

    const long long mod=(long long)(1e9)+7;
    long long n,k;
    cin>>n>>k;

    long long start=-1;
    if(k==1)
    {
        start=1;
    }
    else
    {
        long long a=1;
        long long b=1;
        long long count=2;
        while(1)
        {
            count++;
            long long c=(a%k+b%k)%k;
            // debug(a,b);
            if(c==0)
            {
                // debug(c);
                start=count;
                break;
            }
            a=b;
            b=c;
        }

    }

    // debug(start);
    long long r=((n-1)%mod*start%mod)%mod;
    // debug(r);
    long long exp=(start%mod+r%mod)%mod;

    cout<<exp<<endl;


}