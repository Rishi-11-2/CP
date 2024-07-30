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
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    vector<long long>v;
    long long flag=0;
    for(long long k=1;k<=40;k++)
    {
        sort(arr,arr+n);
        long long cc=arr[n-1]+arr[0];
        cc=(cc+1)/2LL;
        long long count=0;
        for(long long i=0;i<n;i++)
        {
            arr[i]=abs(arr[i]-cc);
            // debug(arr[i]);
            if(arr[i]==0)
            count++;
        }
        v.push_back(cc);
        // debug(cc,count);
        if(count==n)
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<(long long)v.size()<<endl;
    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;
}