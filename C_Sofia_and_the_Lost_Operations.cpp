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
    long long n;
    cin>>n;

    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];

    long long b[n];

    for(long long i=0;i<n;i++)
    cin>>b[i];
    
    long long m;
    cin>>m;

    long long d[m];
    for(long long i=0;i<m;i++)
    cin>>d[i];

    
    long long ud=0;
    multiset<long long>desired;
    multiset<long long>extra;

    for(long long i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        desired.insert(b[i]);
        else
        extra.insert(b[i]);
    }
    for(long long i=m-1;i>=0;i--)
    {
        if(desired.find(d[i])==desired.end())
        {
            if(extra.find(d[i])==extra.end())
            {
                if(ud==0)
                {
                    cout<<"NO"<<endl;
                    return;
                }
            }
            else
            {
                ud=1;
            }
        }
        else
        {
            ud=1;
            desired.erase(desired.find(d[i]));
        }
    }

    if((long long)(desired.size())>0)
    {
        cout<<"NO"<<endl;
        
    }
    else
    {
        cout<<"YES"<<endl;
    }

}