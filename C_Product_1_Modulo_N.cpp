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
    long long n;
    cin>>n;
    // long long len=0;
    // vector<long long>res;
    // function<void(long long,long long,vector<long long>)>f=[&](long long i,long long mod,vector<long long>v)->void{
    //     if(i==n)
    //     {
    //         if(mod==1)
    //         {
    //             if((long long)(v.size())>len)
    //             {
    //                 len=(long long)(v.size());
    //                 res=v;
    //             }
    //         }

    //         return ;
    //     }
    //     f(i+1,mod,v);
    //     v.push_back(i);
    //     f(i+1,(mod%n*i%n)%n,v);
    // };
    // vector<long long>v;
    // f(0,1,v);

    // for(auto it:res)
    // cout<<it<<" ";
    // cout<<endl;

    if(n==2)
    {
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }
    long long flag=1;
    for(long long i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        cout<<n-2<<endl;
        for(long long i=1;i<n-1;i++)
        cout<<i<<" ";
        cout<<endl;

        return ;
    }
    vector<long long>v;
    long long product=1;
    for(long long i=1;i<n;i++)
    {
        if(__gcd(i,n)==1)
        {
            v.push_back(i);
            product=(product%n*i%n)%n;
        }
    }
    if(product!=1)
    {
        v.pop_back();
    }
    // if(product!=1)
    // {
    //     cout<<1<<endl;
    //     cout<<1<<endl;
    //     return;
    // }
    cout<<(long long)(v.size())<<endl;
    for(auto it:v)
    cout<<it<<" ";
     cout<<endl;
}