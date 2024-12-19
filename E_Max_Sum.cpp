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

    long long a[n];
    vector<pair<long long,long long>>v1;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        v1.push_back({a[i],i});
    }

    long long b[n];

    vector<pair<long long,long long>>v2;
    for(long long i=0;i<n;i++)
    {
        cin>>b[i];
        v2.push_back({b[i],i});
    }

    sort(all(v1));
    sort(all(v2));

    long long res=(long long)(1e18); // stupid me setting it to (int)(1e16) whereas it could extend upto 1e18 as well
    long long sum=0;
    multiset<long long,greater<long long>>ss;
    for(long long i=0;i<k;i++)
    {
        sum+=b[v1[i].second];
        ss.insert(b[v1[i].second]);
    }

    res=min(res,v1[k-1].first*sum);

    for(long long i=k;i<n;i++)
    {
        sum-=*ss.begin();
        ss.erase(ss.begin());
        ss.insert(b[v1[i].second]);
        sum+=b[v1[i].second];
        res=min(res,v1[i].first*sum);
    }

    sum=0;
    for(long long i=0;i<k;i++)
    {
        sum+=b[v1[i].second];
    }

    res=min(res,v1[k-1].first*sum);

    for(long long i=k;i<n;i++)
    {
        sum-=b[v1[i-k].second];
        sum+=b[v1[i].second];
        res=min(res,v1[i].first*sum);
    }
    sum=0;
    multiset<pair<long long,long long >, greater<pair<long long,long long>>>s;

    for(long long i=0;i<k;i++)
    {
        sum+=v2[i].first;
        s.insert({a[v2[i].second],i});
    }
    auto it=*s.begin();
    res=min(res,(it.first)*sum);

    for(long long i=k;i<n;i++)
    {
        auto it1=*s.begin();
        sum-=v2[it1.second].first;
        sum+=v2[i].first;
        s.erase(s.begin());
        s.insert({a[v2[i].second],i});
        auto it=*s.begin();
        res=min(res,(it.first)*sum);
    }

    cout<<res<<endl;
    
}