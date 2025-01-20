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
    // cin >> t;
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

    set<long long>s;
    map<long long,long long>mp;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
        s.insert(arr[i]);
    }
    long long count=0;
    for(long long i=n-1;i>=0;i--)
    {
        if(mp[arr[i]]==0)
        continue;

        mp[arr[i]]--;
        auto it=s.lower_bound(2*arr[i]);
        if(it!=s.end())
        {
            long long x=*it;
            mp[x]--;
            if(mp[x]==0)
            {
                s.erase(x);

            }
            count++;
        }
    }

    long long count2=0;
    s.clear();
    mp.clear();
    for(long long i=0;i<n;i++)
    {
        mp[arr[i]]++;
        s.insert(arr[i]);
    }
    for(long long i=0;i<n;i++)
    {
        if(mp[arr[i]]==0)
        continue;
        mp[arr[i]]--;
        auto it=s.lower_bound(2*arr[i]);
        if(it!=s.end())
        {
            long long x=*it;
            mp[x]--;
            if(mp[x]==0)
            {
                s.erase(x);

            }
            count2++;

        }
    }
    cout<<max(count,count2)<<endl;
}