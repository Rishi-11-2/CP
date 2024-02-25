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
    long long n,m;
    cin>>n>>m;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    
    long long div=(n/m);
    map<long long,long long>mp;
    set<pair<long long,long long>, greater<pair<long long,long long>> >s;
    for(long long i=0;i<n;i++)
    {
        if(a[i]>m)
        {
            s.insert({a[i],i});
        }
        else if(mp[a[i]]>=div)
        {
            s.insert({a[i],i});
        }
        else
        {
            mp[a[i]]++;
        }
    }
    long long count=0;
    for(long long i=1;i<=m;i++)
    {
            while(mp[i]<div)
            {
                auto it=*s.begin();
                a[it.second]=i;
                // debug(it.second);
                s.erase(s.begin());
                mp[i]++;
                count++;
            }
        
    }
    // while(!s.empty())
    // {
    //     auto it=*s.begin();
    //     if(it.first>m)
    //     {
    //     count++;
    //         a[it.second]=m;
    //         mp[m]++;
    //     }
    //         s.erase(s.begin());
    // }
    cout<<div<<" "<<count<<endl;

    for(long long i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;

}