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
    string s;
    cin>>s;
    long long n=s.length();

    vector<long long>v;
    for(long long i=0;i<n;i++)
    {
        if(s[i]!='a')
        v.push_back(i);
    }

    long long m=(long long)(v.size());

    vector<long long>factors;
    for(long long i=1;i<=m;i++)
    {
        if(m%i==0)
        {
            factors.push_back(i);
        }
    }
    if(m==0)
    {
        cout<<n-1<<endl;
        return;
    }
    // debug("hi");
    long long ans=0;
    long long l=v[0];
    long long r=n-v[m-1]-1;
    for(auto it:factors)
    {
        string ss=s.substr(v[0],v[it-1]-v[0]+1);
        long long flag=1;
        long long mid=INT_MAX;
        for(long long i=it;i<m;i+=it)
        {
            string s2=s.substr(v[i],v[i+it-1]-v[i]+1);
            if(s2!=ss)
            {
                flag=0;
            }

            mid=min(mid,v[i]-v[i-1]-1);
        }
        if(!flag)continue;
        long long x=0;
        for(long long i=0;i<=l;i++)
        {
            long long y=min(r,mid-i);
            // debug(y);
            if(y<0)
            continue;
            // y=max(y,0);
            x+=(y+1);
        }
        ans+=x;
        // debug(it,x);
    }

    cout<<ans<<endl;
}