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
        solve();
}
void solve()
{
    string s;
    cin>>s;
    long long n=s.length();
    long long i=0;
    vector<long long>v;
    long long count=0;
    while(i<n)
    {
        if(s[i]=='a')
        {
            count++;
            i++;
        }
        else if(s[i]=='b')
        {
            long long j=i+1;
            long long count1=0;
            while(j<n && s[j]!='b')
            {
                if(s[j]=='a')
                count1++;
                j++;
            }
            v.push_back(count);
            v.push_back(count1);
            count=0;
            i=j;
        }
        else    
        i++;
    }
    vector<long long>x;
    if(count>0)
    v.push_back(count);
    for(auto it:v)
    {
        // cout<<it<<" ";
        if(it==0)
        continue;
        x.push_back(it);
    }
    cout<<endl;
    long long sz=(long long)(x.size());
    if(sz==0)
    {
        cout<<0<<endl;
        return;
    }
    const long long mod=(long long)(1e9+7);
    long long res=1;
    for(long long i=0;i<sz;i++)
    {
        res=(res%mod*(x[i]+1)%mod)%mod;
    }
    cout<<res-1<<endl;
}