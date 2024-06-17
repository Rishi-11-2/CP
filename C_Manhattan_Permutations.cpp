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
void f(vector<long long>&v,long long i,long long j,long long k)
{
        // long long i=0;
        long long len=j-i+1;
        
        while((i+1)<=j && k>0)
        {
            swap(v[i],v[i+1]);
            k-=2;
            i+=2;
        }
}
void solve()
{
    long long n,k;
    cin>>n>>k;
    int kk=k;
    vector<long long>v;
    for(long long i=1;i<=n;i++)
    {
        v.push_back(i);
    }
    if(k<=n && k%2==0)
    {
        f(v,0,n-1,k);
        cout<<"Yes"<<endl;
        for(auto it:v)
        cout<<it<<" ";
        cout<<endl;
        return ;
    }

    long long maxm=n-1;

    long long i=0;
    long long j=n-1;
    while(k>0 && i<j)
    {
        long long y=2*abs(v[i]-v[j]);
        if(y<=k)
        {
            k-=y;
            swap(v[i],v[j]);
        }
        j--;
        i++;
        long long len=j-i+1;
        if(len==0)
        continue;
        if(k<=len && k%2==0)
        {
            f(v,i,j,k);
            cout<<"Yes"<<endl;
            for(auto it:v)
            cout<<it<<" ";
            cout<<endl;
            return ;
        }
    }
    if(k==0)
    {
            cout<<"Yes"<<endl;
            for(auto it:v)
            cout<<it<<" ";
            cout<<endl;
            return ;
    }
    cout<<"No"<<" "<<kk<<endl;
}