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
    long long n,m;
    cin>>n>>m;

    vector<pair<long long,long long>>v;
    for(long long i=0;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(all(v));

    long long l=v[0].first;
    long long r=v[0].second;
    for(long long i=1;i<n;i++)
    {
        if(l>v[i].second || r<v[i].first)
        continue;
        l=max(l,v[i].first);
        r=min(r,v[i].second);
    }
    long long l1=1;
    long long r1=l-1;
    long long l2=r+1;
    long long r2=m;
    vector<long long>count1(n,0);
    vector<long long>count2(n,0);
    vector<long long>count3(n,0);
    // cout<<l1<<" "<<r1<<endl;
    for(long long i=0;i<n;i++)
    {
        if(l1>r1)
        continue;
        if(l1>v[i].second || r1<v[i].first)
        {
            // debug(r1,l1,count1[i]);
            count1[i]=-(r1-l1+1);
            continue;
        }
        long long tl=max(v[i].first,l1);
        long long tr=min(v[i].second,r1);
        count1[i]=2*(tr-tl+1)-(r1-l1+1);
        // cout<<count1[i]<<" ";
    }
    // cout<<endl;
    // cout<<l2<<" "<<r2<<endl;
    for(long long i=0;i<n;i++)
    {
        if(l2>r2)
        continue;
        if(l2>v[i].second || r2<v[i].first)
        {
            count2[i]=-(r2-l2+1);
            continue;
        }
        long long tl=max(v[i].first,l2);
        long long tr=min(v[i].second,r2);
        count2[i]=2*(tr-tl+1)-(r2-l2+1);
        // cout<<count2[i]<<" ";
    }
    // cout<<endl;

    long long maxm1=*max_element(all(count1));
    long long maxm2=*max_element(all(count2));
    long long minm1=*min_element(all(count1));
    long long minm2=*min_element(all(count2));

    long long res=max(abs(maxm2-minm2),abs(maxm1-minm1));

    for(long long i=0;i<n;i++)
    {
        cout<<count1[i]<<" "<<count2[i]<<endl;
        count1[i]+=count2[i];
    }
    // cout<<endl;
    long long maxm3=*max_element(all(count1));
    long long minm3=*min_element(all(count1));
    res=max(res,abs(maxm3-minm3));
    cout<<res<<endl;
    
}
