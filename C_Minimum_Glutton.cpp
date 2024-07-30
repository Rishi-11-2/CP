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
bool cmp(pair<long long,long long>&a,pair<long long,long long>&b)
{
    if(a.first==b.first)
    return a.second>b.second;

    return a.first>b.first;

}
void solve()
{
    long long n,x,y;
    cin>>n>>x>>y;

    long long a[n];
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long b[n];
    for(long long i=0;i<n;i++)
    {
        cin>>b[i];
    }

    vector<pair<long long,long long>>v1;
    vector<pair<long long,long long>>v2;

    for(long long i=0;i<n;i++)
    {
        v1.push_back({a[i],b[i]});
        v2.push_back({b[i],a[i]});
    }

    sort(all(v1),cmp);
    sort(all(v2),cmp);

    long long count1=0;
    long long count2=0;
    long long cx=0;
    long long cy=0;
    for(long long i=0;i<n;i++)
    {
        count1++;
        if((v1[i].first+cx)>x || (v1[i].second+cy)>y)
        break;
        cx+=v1[i].first;
        cy+=v1[i].second;
    }
    cx=0;
    cy=0;
    for(long long i=0;i<n;i++)
    {
        count2++;
        if((v2[i].first+cy)>y || (v2[i].second+cx)>x)
        break;
        cy+=v2[i].first;
        cx+=v2[i].second;
    }


    cout<<min(count1,count2)<<endl;
}