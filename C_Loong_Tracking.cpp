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
    long long n,q;
    cin>>n>>q;
    vector<pair<long long,long long>>v(n);
    for(long long i=0;i<n;i++)
    {
        v[i]=make_pair(i+1,0);
    }
    reverse(all(v));
    long long count=0;
    long long x=1;
    long long y=0;
    map<char,pair<long long,long long>>mp;
    mp['U']={0,1};
    mp['D']={0,-1};
    mp['L']={-1,0};
    mp['R']={1,0};
    // mp['U']={0,1};
    for(long long i=1;i<=q;i++)
    {
        long long op;
        cin>>op;
        if(op==1)
        {
            char ch;
            cin>>ch;
            x+=mp[ch].first;
            y+=mp[ch].second;
            v.push_back({x,y});
            count++;
        }
        else
        {
            long long vv;
            cin>>vv;
            long long idx=(n-vv+count);
            cout<<v[idx].first<<" "<<v[idx].second<<endl;   
        }
    }
}