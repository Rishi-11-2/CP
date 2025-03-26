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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;

    string s;
    cin>>s;


    vector<long long>v;

    long long i=0;
    while(i<n)
    {
        if(s[i]=='0')
        {
            v.push_back(0);
            i++;
        }
        else
        {
            
            v.push_back(1);
            i++;
        }
        // i++;
    }
    // for(auto it:v)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    n=(long long)v.size();

    vector<long long>prefix(n,0);
    vector<long long>suffix(n,0);
    long long curr=0;
    long long ss=0;
    for(long long i=0;i<n;i++)
    {
        if(v[i]==0)
        ss+=curr;
        if(v[i]==1)
        curr++;
        prefix[i]=ss;
    }
    curr=0;
    ss=0;
    for(long long i=n-1;i>=0;i--)
    {
        if(v[i]==0)
        ss+=curr;
        if(v[i]==1)
        curr++;
        suffix[i]=ss;
        // cout<<suffix[i]<<" ";
    }
    // cout<<endl;
    long long res=(long long)(1e18);
    for(long long i=0;i<n;i++)
    {
        // debug(i,suffix[i],prefix[i]);
        res=min(res,suffix[i]+prefix[i]);
    }

    cout<<res<<endl;

}