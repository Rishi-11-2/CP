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

    long long arr[n+1];
    for(long long i=1;i<=n;i++)
    cin>>arr[i];
    
    vector<long long>prefix(n+1,0);

    for(long long i=1;i<=n;i++)
    {
        prefix[i]=prefix[i-1]+arr[i];
    }

    function<long long(long long,long long)>sum=[&](long long l,long long r)->long long{

        return (prefix[r]-prefix[l-1]);
    };

    for(long long i=1;i<=q;i++)
    {
        long long l,r;
        cin>>l>>r;
        long long rd=(r/n);
        long long rm=(r%n);
        long long rleft=rm-(n-rd);
        long long sumr=rd*sum(1,n);

        if(rm>0)
        {
            long long rr=rm;
            if(rleft>=1)
            rr=n;
            else
            rr=rm+rd;
            sumr+=sum(rd+1,rr);
        }
        if(rleft>=1)
        {
            sumr+=sum(1,rleft);
        }

        l-=1;
        long long ld=(l/n);
        long long lm=(l%n);
        long long lleft=lm-(n-ld);
        long long suml=ld*sum(1,n);

        if(lm>0)
        {
            long long ll=lm;
            if(lleft>=1)
            ll=n;
            else
            ll=lm+ld;
            suml+=sum(ld+1,ll);
        }

        if(lleft>=1)
        {
            suml+=sum(1,lleft);
        }

        // debug(sumr,suml);
        cout<<(sumr-suml)<<endl;
    }
}