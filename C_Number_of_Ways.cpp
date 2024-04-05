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
    map<long long,long long>mp1;
    long long ss=0;
    long long arr[n];
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        ss+=arr[i];
        mp1[ss]++;
    }
    

    if(ss==0)
    {
        long long x=mp1[0];
        long long res=(x-1)*(x-2);
        res=res/(2LL);
        cout<<res<<endl;
        return;
    }

    if(ss%3)
    {
        cout<<0<<endl;
        return;
    }
    long long res=0;
    long long s=0;
    map<long long,long long>mp;
    for(long long i=0;i<n;i++)
    {
        s+=arr[i];
        mp[s]++;
        if(s==2*(ss/3))
        {
            // debug(ss/3);
            res+=mp[ss/3];
        }
    }
    cout<<res<<endl;
}