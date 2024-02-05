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
    long long a,b,c;
    cin>>a>>b>>c;
    long long m;
    cin>>m;
    long long s=a+b+c;
    vector<pair<long long,string>>v;
    for(long long i=1;i<=m;i++)
    {
        long long val;
        cin>>val;
        string s;
        cin>>s;
        v.push_back({val,s});
    }
    long long sum=0;
    
    sort(all(v));
    map<string,long long>mp;
    mp["USB"]=a;
    mp["PS/2"]=b;
    // mp["U"]=a;
    long long count=0;
    for(auto it:v)
    {
        if(mp[it.second]>0)
        {
            sum+=it.first;
            mp[it.second]--;
            count++;
        }
        else if(c>0)
        {
            c--;
            sum+=it.first;
            count++;
        }
    }
    cout<<count<<" "<<sum<<endl;

}