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
    long long n,x;
    cin>>n>>x;

    long long mex=0;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);

    for(long long i=0;i<n;i++)
    {
        if(arr[i]==mex)
        {
            arr[i]=-1;
            mex++;
        }
    }
    map<long long,multiset<long long>>mp;
    for(long long i=0;i<n;i++)
    {
        if(arr[i]==-1)
        continue;
        
        mp[arr[i]%x].insert(arr[i]);
    }
    int count=0;
    while(1)
    {
        long long idx=(mex)%x;
        // debug(mex,*s.begin());
        int sz=(int)mp[idx].size();
        count++;
        if(sz==0)
        break;
        int bb=*mp[idx].begin();
        if(mex>=bb)
        {
            // debug(mex,*s.begin());
            mex++;
            mp[idx].erase(mp[idx].begin());
            continue;
        }
        break;
    }
    cout<<mex<<endl;
}