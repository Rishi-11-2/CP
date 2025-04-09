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
    long long n;
    cin>>n;

    map<long long,vector<long long>>mp;
    for(long long i=0;i<n;i++)
    {
        long long x;
        cin>>x;

        mp[x].push_back(i+1);
    }

    long long res=-1;
    long long idx=-1;
    for(auto it:mp)
    {
        long long s=0;
        long long prev=-1;
        for(auto i:it.second)
        {
            s++;
            if(prev!=-1)
            {
                s-=((i-prev)-1);
            }
            // debug(it.first,s,i,prev);
            if(s<=0)
            {
                // debug(it.first,i);
                s=1;
                prev=i;
            }
            if(s>res)
            {
                res=s;
                idx=it.first;
            }
            prev=i;
        }
    }
    long long s=0;
    long long prev=-1;
    long long l=-1;
    long long r=-1;

    long long left=-1;
    long long right=-1;
    for(auto i:mp[idx])
    {
        if(l==-1)
        l=i;
        s++;
        r=max(r,i);
        if(prev!=-1)
        {
            s-=(i-prev)-1;
        }
        prev=i;
        if(s<=0)
        {
            l=i;
            r=i;
            s=1;
            prev=i;
        }
        if(s==res)
        {
            left=l;
            right=r;
        }
    }

    cout<<idx<<" "<<left<<" "<<right<<endl;

}