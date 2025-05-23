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
    long long n,k;
    cin>>n>>k;

    long long arr[n];

    set<long long>s;
    map<long long,long long>mp;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
        s.insert(arr[i]);
    }
    vector<long long>v(all(s));
    s.clear();

    long long m=(long long)v.size();

    long long ans=0;
    long long sum=0;
    long long prev=-1;

    // for(auto it:v)
    // {
    //     debug(it,mp[it]);
    // }

    for(long long i=0;i<min(k,m);i++)
    {

        if(i && (v[i]-v[i-1])>1)
        {
            s.clear();
            ans=max(ans,sum);
            sum=mp[v[i]];
        }
        else
        {
            sum+=mp[v[i]];
        }
        ans=max(ans,sum);
        s.insert(i);
    }    

    for(long long i=k;i<m;i++)
    {
        while((long long)s.size()>0)
        {
           long long f=*s.begin();
           if(f<(i-k+1))
           {
              sum-=mp[v[f]];
              s.erase(s.begin());
           }
           else
           break;
        }
        
        if(i && (v[i]-v[i-1])>1)
        {
            s.clear();
            ans=max(ans,sum);
            sum=mp[v[i]];
        }
        else
        {
            sum+=mp[v[i]];
        }
        // debug(i,sum);
        s.insert(i);
        ans=max(ans,sum);

    }
    cout<<ans<<endl;
}