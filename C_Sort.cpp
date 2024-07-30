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
    long long n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    string t;
    cin>>t;

    vector<vector<long long>>prefixS(n+1,vector<long long>(26,0));
    for(long long i=1;i<=n;i++)
    {
        prefixS[i]=prefixS[i-1];
        prefixS[i][s[i-1]-'a']++;
    }
    vector<vector<long long>>prefixT(n+1,vector<long long>(26,0));
    for(long long i=1;i<=n;i++)
    {
        prefixT[i]=prefixT[i-1];
        prefixT[i][t[i-1]-'a']++;
    }

    for(long long i=1;i<=q;i++)
    {
        long long l,r;
        cin>>l>>r;

        auto v1=prefixS[r];
        auto v2=prefixS[l-1];
        for(long long i=0;i<26;i++)
        {
            v1[i]-=v2[i];
        }
        auto x1=prefixT[r];
        auto x2=prefixT[l-1];
        for(long long i=0;i<26;i++)
        {
            x1[i]-=x2[i];
        }
        long long count=0;

        for(long long i=0;i<26;i++)
        {
            // debug(x1[i],v1[i],i);
            count+=abs(x1[i]-v1[i]);
        }
        cout<<count/2<<endl;
    }
}