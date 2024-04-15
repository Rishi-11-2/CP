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
    long long n,m,k;
    cin>>n>>m>>k;

    long long a[n];

    for(long long i=0;i<n;i++)
    cin>>a[i];

    long long b[m];

    for(long long i=0;i<m;i++)
    cin>>b[i];
    
    map<long long,long long>x;

    

    map<long long,long long>y;

    multiset<long long>s;
    for(long long i=0;i<m;i++)
    {
        s.insert(b[i]);
        y[b[i]]++;
    }

    long long cc=0;
    set<long long>vis;
    map<long long,set<long long>>mp;
    for(long long i=0;i<m;i++)
    {
        x[a[i]]++;
        if((s.find(a[i])!=s.end()))
        {
            if(x[a[i]]<=y[a[i]])
            {
               vis.insert(i);
               cc++;
            }
            else
            {
                mp[a[i]].insert(i);
            }
            // debug(i);
        }
    }

    long long res=0;

    if(cc>=k)
    {
        res++;
    }
    // debug(res);
    for(long long i=m;i<n;i++)
    {
        x[a[i-m]]--;

        if(vis.find(i-m)!=vis.end())
        {
            vis.erase(i-m);
            if((long long)(mp[a[i-m]].size())>0)
            {
                auto it=mp[a[i-m]].begin();
                vis.insert(*it);
                mp[a[i-m]].erase(it);
            }
            else
            cc--;
        }
        x[a[i]]++;
        if((s.find(a[i])!=s.end()))
        {
            if(x[a[i]]<=y[a[i]])
            {
               vis.insert(i);
               cc++;
            }
            else
            {
                mp[a[i]].insert(i);
            }
            // debug(i);
        }
        // debug(i,cc);
        if(cc>=k)
        {
            res++;
        }
    }

    cout<<res<<endl;
}