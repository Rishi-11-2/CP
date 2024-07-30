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
    map<long long,long long>mpx;
    map<long long,long long>mpy;
    for(long long i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
        mpx[x]++;
        mpy[y]++;
    }
    long long count=0;
    for(long long i=0;i<n;i++)
    {
        for(long long j=i+1;j<n;j++)
        {
            mpx[v[i].first]--;
            mpx[v[j].first]--;
            mpy[v[i].second]--;
            mpy[v[j].second]--;

            if(mpx[v[i].first] && mpy[v[j].second])
            {
                // debug("h");
            }
            else if(mpy[v[i].second] && mpx[v[j].first])
            {
                // debug("hi");
            }
            else if(v[i].second==v[j].second || v[i].first==v[j].first)
            {
                // debug("ho");
            }
            else
            {
                count++;
                mpx[v[i].first]++;
                mpx[v[j].second]++;
            }
            mpx[v[i].first]++;
            mpx[v[j].first]++;
            mpy[v[i].second]++;
            mpy[v[j].second]++;
        }
    }

    cout<<count<<endl;

}