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

    long long arr[n];

    for(long long i=0;i<n;i++)
    cin>>arr[i];

    long long count=0;

    vector<vector<long long>>v;

    for(long long i=0;i<n-2;i++)
    {
        vector<long long>x;
        x.push_back(arr[i]);
        x.push_back(arr[i+1]);
        x.push_back(arr[i+2]);
        v.push_back(x);
    }
    long long m=(long long)(v.size());

    map<string ,set<long long>>mp;
    map<string,map<long long,long long>>mp2;
    for(long long i=0;i<3;i++)
    {
        set<long long>x;
        
        for(long long j=i+1;j<3;j++)
        {
            for(long long k=0;k<3;k++)
               x.insert(k);

            x.erase(i);
            x.erase(j);
            for(auto it:v)
            {
                string sss=to_string(it[i])+to_string(it[j])+to_string(i)+to_string(j);
                mp[sss].insert(it[*x.begin()]);
                mp2[sss][it[*x.begin()]]++;
            }
        }
    }

    for(auto it:mp)
    {
        auto s=it.second;
        auto vv=mp2[it.first];
        long long sum=0;
        for(auto i:s)
        {
            sum+=vv[i];
        }
        for(auto it:s)
        {
            sum-=vv[it];
            count+=(sum*vv[it]);
        }
    }
    cout<<count<<endl;
}