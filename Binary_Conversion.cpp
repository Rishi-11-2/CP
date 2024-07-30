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
    long long n,k;
    cin>>n>>k;

    string s;
    cin>>s;
    string t;
    cin>>t;
    long long one1=0;
    long long zero1=0;
    long long one2=0;
    long long zero2=0;
    for(char c:s)
    {
        if(c=='0')
        zero1++;
        else
        one1++;
    }
    for(char c:t)
    {
        if(c=='0')
        zero2++;
        else
        one2++;
    }
    if(one1!=one2)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(one1==one2 && (one1==n||zero1==n))
    {
        cout<<"YES"<<endl;
        return;
    }
    long long count=0;
    for(long long i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        count++;
    }
    if(count%2)
    {
        cout<<"NO"<<endl;
        return;
    }
    count=count/2LL;

    long long d=k-count;
    // debug(d);
    if((d>0) && (d%2) && n==2)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(d<0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }

}