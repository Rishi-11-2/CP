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
    long long n,m;
    cin>>n>>m;

    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];

    long long b[n];

    vector<long long>one;
    vector<long long>two;
    for(long long i=0;i<n;i++)
    {
        cin>>b[i];

        if(b[i]==1)
        {
            one.push_back(a[i]);
        }
        else
        {
            two.push_back(a[i]);
        }
    }

    sort(all(one),greater<long long>());     
    sort(all(two),greater<long long>());

    long long os=(long long)(one.size());

    long long ts=(long long)(two.size());


    for(long long i=1;i<os;i++)
    {
        one[i]+=one[i-1];
    }     

    for(long long i=1;i<ts;i++)
    {
        two[i]+=two[i-1];
    }

    long long res=(long long)(1e18);

    long long j=ts-1;
    for(long long i=0;i<os;i++)
    {
        long long rem=m-one[i];

        while(j-1>=0 && two[j-1] >=rem)
        j--;


        if(j>=0 && (one[i]+two[j])>=m)
        {
            res=min(res,(i+1)+(j+1)*2);
        }
        if(one[i]>=m)
        {
            res=min(res,(i+1));
        }
    }
    j=os-1;
    for(long long i=0;i<ts;i++)
    {
        long long rem=m-two[i];

        while((j-1)>=0 && one[j-1]>=rem)
        j--;
        
        if(j>=0 && (one[j]+two[i])>=m)
        {
            res=min(res,(i+1)*2+(j+1));
        }
        if(two[i]>=m)
        {
            res=min(res,(i+1)*2);
        }
    }

    if(res==(long long)(1e18))
    res=-1;
    cout<<res<<endl;

}