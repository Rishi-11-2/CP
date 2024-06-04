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
    string s;
    cin>>s;
    long long n=s.length();

    vector<long long>c(n,0);

    long long count=0;

    for(long long i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            count++;
        }
        else
        {
            count--;
        }
        c[i]=count;
    }
    map<long long,long long>mp;
    map<long long,long long>flag;
    long long res=0;
    for(long long i=0;i<n;i++)
    {
        // cout<<c[i]<<" ";
        if(c[i]%2)
        {
            long long x=c[i]-1;
            x=x/2;
            mp[x]=0;
        }
        
        res+=mp[c[i]];
        mp[c[i]]++;
    }
    // cout<<"\n";
    cout<<res<<endl;
}