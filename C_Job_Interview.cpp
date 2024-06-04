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

    long long k=n+m+1;

    long long a[k],b[k];

    for(long long i=0;i<k;i++)
    cin>>a[i];
    
    for(long long i=0;i<k;i++)
    cin>>b[i];


    long long c1=0,c2=0,a1=0,b1=0,a2=0,b2=0;

    vector<long long>c(k);

    long long res=0;
    for(long long i=0;i<k;i++)
    {
        if(a[i]>b[i])
        {
            if(c1<n)
            {
                res+=a[i];
                c[i]=a[i];
            }
            else if(c1==n)
            {
                a1=i;
                a2=(a[i]-b[i]);
                c[i]=b[i];
                res+=b[i];
            }
            else
            {
                c[i]=b[i];
                res+=b[i];
            }
            c1++;
        }
        else
        {
            if(c2<m)
            {
                c[i]=b[i];
                res+=b[i];
            }
            else if(c2==m)
            {
                b1=i;
                b2=(b[i]-a[i]);
                c[i]=a[i];
                res+=a[i];
            }
            else
            {
                c[i]=a[i];
                res+=a[i];
            }
            c2++;
        }

    }

    for(long long i=0;i<k;i++)
    {
        long long ans=res-c[i];
        if(a[i]>b[i])
        {
            if(i<a1)
            {
                ans+=a2;
            }
        }
        else
        {
            if(i<b1)
            {
                ans+=b2;
            }
        }

        cout<<ans<<" ";
    }
    cout<<endl;
}
