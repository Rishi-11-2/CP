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
class FenwickTree{
    public:
    vector<long long>bit;
    long long n;
    FenwickTree(long long s)
    {
        n=s;
        bit.assign(n+1,0);
    }

    void update(long long val,long long idx)
    {
        long long i=idx;
        while(i<=n)
        {
            bit[i]+=val;
            i+=(i&-i);
        }
    }

    long long query(long long idx)
    {
        long long i=idx;
        long long s=0;
        while(i>0)
        {
            s+=bit[i];
            i-=(i&-i);
        }
        return s;
    }
    long long query_range(long long l,long long r)
    {
        return query(r)-query(l-1);
    }

};
void solve()
{
    long long n;
    cin>>n;

    long long a[n+1];
    for(long long i=1;i<=n;i++)
    cin>>a[i];
    
    long long q;
    cin>>q;

    vector<pair<long long,long long>>v;
    map<long long,vector<pair<long long,long long>>>mp;
    for(long long i=1;i<=q;i++)
    {
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
        mp[y].push_back({x,y});
    }

    // sort(all(v));

    long long maxm=*max_element(a,a+n);

    FenwickTree fk(n);

    gp_hash_table<long long,long long>previousOccurences;
    gp_hash_table<long long,long long>mp1;
    for(long long i=1;i<=n;i++)
    {
        if(mp1.find(a[i])==mp1.end())
        {
            mp1[a[i]]=i;
            previousOccurences[i]=-1;
        }
        else
        {
            previousOccurences[i]=mp1[a[i]];
            mp1[a[i]]=i;
        }
    }
    map<pair<long long,long long>,long long>ans;
    for(long long i=1;i<=n;i++)
    {
        if(previousOccurences[i]!=-1)
        {
            fk.update(-a[i],previousOccurences[i]);
        }
        fk.update(a[i],i);

        for(auto it:mp[i])
        {
            ans[it]=fk.query_range(it.first,it.second);
        }
    }

    for(auto it:v)
    {
        cout<<ans[it]<<endl;
    }

}