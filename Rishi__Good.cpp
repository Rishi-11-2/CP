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
    long long n,k;
    cin>>n>>k;

    long long arr[n];

    for(long long i=0;i<n;i++)
    cin>>arr[i];

    long long count=0;

    map<long long,vector<long long>>mp;
    sort(arr,arr+n);
    for(long long i=0;i<n;i++)
    {
        mp[arr[i]%k].push_back(arr[i]);

    }
    long long count1=0;
    for(auto it:mp)
    {
        long long sz=(long long)(it.second.size());
        if(sz%2 )
        count1++;
    }
    if(count1>1 && n%2)
    {
        cout<<-1<<endl;
        return;
    }
    if(count1>0 && n%2==0)
    {
        cout<<-1<<endl;
        return;
    }
    vector<long long>vvv;
    vector<vector<long long>>dp;
    function<long long(long long,long long )>f=[&](long long i,long long flag)->long long{
        // long long i=0;

        if(i+1>=(long long)(vvv.size()))
        {
            return 0;
        }
        if(dp[i][flag]!=-1)
        return dp[i][flag];
        long long res=(vvv[i+1]-vvv[i])+f(i+2,flag);
        if(flag==0)
        res=min(res,f(i+1,1));
        return dp[i][flag]= res;
    };
    long long res=0;
    for(auto it:mp)
    {
        long long sz=(long long)(it.second.size());


        auto v=it.second;
        // sort(all(v));
        // cout<<it.first<<" ";
        // for(auto it:v)
        // cout<<it<<" ";
        // cout<<endl;
        long long count=0;
        long long count1=0;
        if(sz%2==0)
        {
            for(long long i=0;i+1<sz;i+=2)
            {
                long long diff=(v[i+1]-v[i]);
                count1+=(diff/k);
            }
            count=count1;
        }
        if(sz%2)
        {
            count1=0;
            vvv=v;
            
            dp.resize(sz+1,vector<long long>(2));
            dp.assign(sz+1,vector<long long>(2,-1));



            count=f(0,0);
            // debug(count);
            count=count/k;
        }
        res+=count;
    }

    cout<<res<<endl;
}