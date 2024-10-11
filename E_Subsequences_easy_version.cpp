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
    long long n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    priority_queue<pair<long long,string>,vector<pair<long long,string>>,greater<pair<long long,string>>>pq;
    long long ans=0;
    map<string,long long>dp;
    dp[s]=0;
    long long count=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        long long d=it.first;
        string s=it.second;
        ans+=d;
        count++;
        // debug(s,d,count);
        if(count==k)
        break;
        if((long long)s.length()>0)
        {
            string z=s.substr(1);
           if( dp.find(z)==dp.end())
           {
             pq.push({d+1,z});
             dp[z]=d+1;
           }
        }
        long long len=s.length();
        for(long long i=1;i<len;i++)
        {
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            string z=left+right;
            if(dp.find(z)==dp.end())
            {
                pq.push({d+1,z});
                dp[z]=d+1;
            }
        }
    }
    if(count<k)
    {
        ans=-1;
    }
    cout<<ans<<endl;
}