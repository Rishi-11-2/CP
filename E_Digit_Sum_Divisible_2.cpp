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
//(data type to be stored (pair,long long ,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong long s)
typedef tree < pair<long long ,long long >, null_type,less<pair<long long ,long long >>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long  t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
long long  f(long long  n)
{
    string s=to_string(n);

    long long  ans=0;
    for(long long  i=0;i<s.length();i++)
    {
        ans+=(s[i]-'0');
    }
    return ans;
}
void solve()
{

    string s;

    cin>>s;

    long long  n=-1;

    debug(s);
    if(s.length()<7)
    {
        n=stoi(s);
    }
    long long  m=(long long )(1e5);
    map<long long ,string>mp;

    for(long long  i=1;i<=m;i++)
    {
        for(long long  j=(2LL*i);j<=m;j+=i)
        {
            if(n!=-1 && j>=(2*n))
            break;
            long long  x=f(j);

            if(x%i==0)
            {
                mp[j]=1;
            }
        }
    }
    debug(s);
    char c='0';
    for(auto it:mp)
    {
        int j=
        auto ss=it.second;

        while(ss.length()<s.length())
        {
            ss=ss+c;
        }
        debug(it.first,ss);
    }


}