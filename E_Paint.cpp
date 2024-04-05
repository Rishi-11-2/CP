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
    long long h,w,m;
    cin>>h>>w>>m;
    vector<vector<long long>>operations;
    for(long long i=1;i<=m;i++)
    {
        long long t,a,x;
        cin>>t>>a>>x;

        vector<long long>v;
        v.push_back(t);
        v.push_back(a);
        v.push_back(x);

        operations.push_back(v);

    }
    map<long long,long long>mp;
    long long zero=h*w;
    long long row=w;
    long long col=h;
    set<long long>rows;
    set<long long>cols;
    for(long long i=m-1;i>=0;i--)
    {
        auto v=operations[i];
        long long t=v[0];
        long long a=v[1];
        long long x=v[2];
        // debug(t,a,x);
        if(t==1)
        {
            if(rows.find(a)!=rows.end())
            continue;
        }
        if(t==2)
        {
            if(cols.find(a)!=cols.end())
            continue;
        }
        // debug("hello");
        if(t==1)
        {
            // debug(t);
            if(row!=0)
            mp[x]+=row;

            // debug(zero,row);
            if(x!=0)
            zero-=row;
            // cout<<mp[x]<<endl;
            rows.insert(a);
        }
         if(t==2)
        {
            if(col!=0)
            mp[x]+=col;
            
            // debug(zero,col);
            if(x!=0)
            zero-=col;
            cols.insert(a);
        }
        if(t==1)
        {
            col--;
        }
        if(t==2)
        {
            row--;
        }
    }
    // debug(zero);
    if(zero!=0)
    mp[0]=zero;
    cout<<(long long)(mp.size())<<endl;
    for(auto it:mp)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
}
