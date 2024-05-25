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
    long long n;
    cin>>n;

    vector<pair<long long,long long>>v;

    map<long long,long long>mp1;
    map<long long,long long>mp2;

    vector<long long>st;
    set<long long>cost;

    set<long long>s;
    for(long long i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;

        v.push_back({x,y});

        st.push_back(x);
        mp1[x]=i;
        mp2[i]=x;
        s.insert(i);
        cost.insert(y);
    }

    sort(all(v));
    // sort(all(cost));
    // for(auto it:v)
    // {
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    for(long long i=0;i<n-1;i++)
    {
        cost.erase(v[i].second);
        long long minm=*cost.begin();
        // debug(maxm,v[i].second);
        if(minm<v[i].second)
        {
            // debug(mp1[v[i].first],v[i].first);
            s.erase(mp1[v[i].first]);
        }
    }

    cout<<(long long)(s.size())<<endl;

    for(auto i:s)
    cout<<i<<" ";
    
    cout<<endl;

}