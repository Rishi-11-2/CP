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

    long long arr[n];

    for(long long i=0;i<n;i++)
    cin>>arr[i];

    map<long long,long long>c;

    map<long long,long long>f;
    map<long long,long long>b;


    vector<long long>v;
    
    for(long long i=n-1;i>=0;i--)
    {
        if(c.find(arr[i])!=c.end())
        {
            f[i]=c[arr[i]]-1;
        }
        else
        {
            f[i]=n+2;
        }
        c[arr[i]]=i+1;
        v.push_back(f[i]);
    }
    
    c.clear();

    sort(all(v));

    // for(auto it:v)
    // cout<<it<<" ";

    // cout<<endl;

    long long count=0;
    for(long long i=0;i<n;i++)
    {
        if(c.find(arr[i])!=c.end())
        {
            b[i]=c[arr[i]]+1;
        }
        else
        {
            b[i]=-1;
        }
        c[arr[i]]=i+1;
        if(i>0 && (arr[i]==arr[i-1]))
        {
            count+=0;
            continue;
        }
        auto it=upper_bound(all(v),b[i]-1)-v.begin();

        // debug(i,it,b[i]);
        count+=(i-it);
    }

    

    cout<<count<<endl;
}