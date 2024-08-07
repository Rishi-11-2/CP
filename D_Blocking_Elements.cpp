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
    long long n;
    cin>>n;
    vector<long long>arr(n+2,0);
    vector<long long>prefix(n+2,0);
    for(long long i=1;i<=n;i++)
    {
        cin>>arr[i];
        prefix[i]=arr[i]+prefix[i-1];
    }
    long long low=0;
    long long high=(long long)(1e16);
    long long res=0;
    arr[n+1]=0;
    arr[0]=0;
    prefix[n+1]=prefix[n];
    function<long long(long long)>f=[&](long long m)->long long{
       vector<long long>dp(n+3,0);

       deque<long long>dq;
       dq.push_back(0);
       long long j=0;
       for(long long i=1;i<=n+1;i++)
       {
          while(i>0 && !dq.empty() &&  ((prefix[i-1]-prefix[dq.front()])>m))
          {
            dq.pop_front();
          }
          dp[i]=arr[i]+dp[dq.front()];

          while(!dq.empty() && dp[dq.back()]>=dp[i]) // maintaining a monotonic deque
          {
            dq.pop_back();
          }
          dq.push_back(i);
       }
       return (dp[n+1]<=m);
    };
    // bool a=f(5);
    while(low<=high)
    {
        long long mid=(low+high)/2LL;
        if(f(mid))
        {
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    cout<<res<<endl;
}