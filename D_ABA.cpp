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
    string s;
    cin>>s;

    long long n=s.length();

    vector<vector<long long>>prefix(n+1,vector<long long>(26,0));
    vector<vector<long long>>suffix(n+1,vector<long long>(26,0));

    for(long long i=n-1;i>=0;i--)
    {
        suffix[i]=suffix[i+1];
        suffix[i][s[i]-'A']++;
    }
    long long ans=0;
    for(long long i=0;i<n;i++)
    {
        // for(long long)
        if(i)
        prefix[i]=prefix[i-1];
        suffix[i][s[i]-'A']--;
        for(long long j=0;j<26;j++)
        {
            // debug(i,prefix[i][j],suffix[i][j]);
            ans+=(prefix[i][j]*suffix[i][j]);
        }
        prefix[i][s[i]-'A']++;
    }
    cout<<ans<<endl;
}