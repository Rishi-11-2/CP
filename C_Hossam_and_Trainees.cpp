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
vector<long long>v;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    vector<long long>isPrime((long long)(1e5)+1,1);
    isPrime[1]=isPrime[0]=0;
    for(long long i=2;i*i<=10000;i++)
    {
        if(isPrime[i])
        {
            for(long long j=i*i;j<=10000;j+=i)
            {
                isPrime[j]=0;
            }
        }
    }
    v.clear();
    for(long long i=2;i<=10000;i++)
    {
        if(isPrime[i])
        {
            v.push_back(i);
        }
    }
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
    unordered_map<long long,long long>mp;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        // mp[arr[i]]++;

    }
    // cout<<(v.size())<<endl;
    // cout<<v[(int)(v.size())-1]<<endl;
    for(auto i:v)
    {
        for(long long j=0;j<n;j++)
        {
            long long x=1;
            if((arr[j]%i)==0)
            {
                mp[i]++;

            }
            while(arr[j]%i==0)
            {
                arr[j]=arr[j]/i;
            }
            if(mp[i]>=2)
            {
                // cout<<i<<endl;
                cout<<"YES"<<endl;
                return;
            }
            // mp[arr[j]]++;
        }

    }
    for(long long i=0;i<n;i++)
    {
        if(arr[i]==1)
        continue;
        cout<<arr[i]<<endl;
        mp[arr[i]]++;
        if(mp[arr[i]]>=2)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}