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
//(data type to be stored (pair,long long ,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong long s)
typedef tree < pair<long long ,long long >, null_type,less<pair<long long ,long long >>,rb_tree_tag,tree_order_statistics_node_update > pbds;
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
    long long  n,q;
    cin>>n>>q;

    gp_hash_table<long long ,long long >gp;

    long long  arr[n];

    for(long long  i=0;i<n;i++)
    {
        cin>>arr[i];
        gp[arr[i]]++;
    }
    long long ans=0;
    for(auto it:gp)
    {
        ans+=((it.second)*(it.second+1))/2;
    }

    vector<long long >res;
    for(long long  i=0;i<q;i++)
    {
        long long  p,x;
        cin>>p>>x;

        p--;
        ans-=gp[arr[p]];
        gp[arr[p]]--;
        arr[p]=x;
        gp[arr[p]]++;
        ans+=gp[arr[p]];

        res.push_back(ans);
    }

    for(auto it:res)
    cout<<it<<endl;

}