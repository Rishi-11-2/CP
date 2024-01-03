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
long long binPow(long long a,long long b,long long mod)
{
    long long res=1;
    while(b>0)
    {
        if(b&1)
        res=(res%mod*a%mod)%mod;
        
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }

    return res;
}
void solve()
{
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];

    long long mod=998244353;
    vector<long long>prevGreater(n,-1);
    stack<long long>st;
    for(long long i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]<arr[i])
        {
            st.pop();
        }
        prevGreater[i]=(st.empty())?-1:st.top();
        st.push(i);
    }
    while(!st.empty())
    st.pop();
    
    vector<long long>nextGreater(n,-1);
    for(long long i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]<arr[i])
        {
            st.pop();
        }
        nextGreater[i]=(st.empty())?-1:st.top();
        st.push(i);
    }
    vector<long long>res;
    vector<long long>x(n,0);
    long long count=0;
    for(long long i=0;i<n;i++)
    {
        if(nextGreater[i]!=-1 && prevGreater[i]!=-1)
        {
            x[nextGreater[i]]=(x[nextGreater[i]]%mod+1%mod)%mod;
        }
        count=(count%mod+x[i]%mod)%mod;
        long long ans=binPow(2,count,mod);
        res.push_back(ans);
    }
    for(auto it:res)
    cout<<it<<" ";
    
    cout<<endl;
}