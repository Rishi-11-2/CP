#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n,m;
    cin>>n>>m;

    if(m==0)
    {
        cout<<n<<endl;
        return;
    }

    long long res=n|(n+m);
    // debug(res);
    // long long yy=max(0LL,n-m);
    // res=res|(yy);
    /*
    1279 -10011111111
    1145 -10001111001
    1159 -10010000111
    1151 -10001111111
    

    19198 -100101011111110
    19208 -100101100001000
    19455 -100101111111111
    */
    
    long long len=log2(m);
    // if(m>(1LL<<len))
    // len++;
    for(long long i=0;i<=len;i++)
    {
        res=res|(1LL<<i);
    }

    // if(n>0)
    // {
        long long xa=0;
        long long xb=0;
        for(long long i=0;i<32;i++)
        {
            if(n&(1LL<<i))
            {
                xa=xa|(1LL<<i);
            }
            long long yy=xa|(1LL<<i);
            // debug(xa,yy,xb);
            if((yy-xb)<=m && yy<=n)
            {
                res=res|xb;
            }
            xb=xb|(1LL<<i);
        }
    // }

    cout<<res<<endl;

/*
    1891012 - 111001101101011000100
    1891031 - 111001101101011010111
    1891007 - 111001101101010111111
    1891039 - 111001101101011011111
    1891071 - 111001101101011111111
 */
    long long i=n;
    long long res1=n;

    // while(i<n+m)
    // {
    //     // if(i&(1LL<<5))
    //     // {
    //     //     cout<<i<<endl;
    //     // }
    //     res1=res1|i;
    //     i++;
    // }
    // while(i>max(0LL,n-m))
    // {
    //     // if(i&(1LL<<5))
    //     // {
    //     //     cout<<i<<endl;
    //     // }
    //     res1=res1|i;
    //     i--;
    // }
    // cout<<res1<<endl;
}