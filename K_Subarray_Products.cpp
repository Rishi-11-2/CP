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
    /*
    let's take ,
dp[i] = sum of happiness for all subarray starting from index i

now, think how u can write ur transition..
lets say u have k=3,
then, dp[4] = a[4] + a[4]*a[5] + a[4]*a[5]*a[6]
and, ur dp[3] = a[3] + a[3]*a[4] + a[3]*a[4]*a[5] = a[3] + a[3]*(a[4] + a[4]*a[5]) = a[3] + a[3]*( dp[4] - a[4]*a[5]*a[6] )

i.e. u can say.. dp[i] = a[i] + a[i]*(dp[i+1]-p)
where, p=product(i+1, i+k) (edited)
now, if u can calculate this product of a range in O(1) or O(logn) time.. ur all n dp states can be calculated in O(n) or O(nlogn) time..
then, ur final answer would be the sum of all the n dp states.
now, to calculate the product of a range.. u can use prefix-product... but, there is a problem with that..
since, u need to take %M in each step(or else ur product may exceed long long range),.. so, while calculating the product of  range from prefix, u will have to do pr[r]/pr[l-1], but.. in %M, u will have to take modulo inverse to do division... but, here we r not given that "M is prime", so.. we can't take modulo inverse for not-prime M..
so, what u can do is.. u can use either sparse table/segment tree.. to compute the product of a range in log(n) time.
thus, ur overall complexity would be O(nlogn)
    */
    long long n,k,m;
    cin>>n>>k>>m;

    long long arr[n];

    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    vector<long long>dp(n+1,1);

    long long res=0;
    dp[n-1]=arr[n-1];
    for(long long i=n-2;i>=n-k;i--)
    {
        dp[i]=(arr[i]+(arr[i]%m*dp[i+1]%m)%m)%m;
    }
    long long tree[4*n];

    function<void(long long,long long,long long)>build=[&](long long ss,long long se,long long si)->void{

        if(ss==se)
        {
            tree[si]=arr[ss];
            return ;
        }

        long long mid=(ss+se)/2;

        build(ss,mid,2*si+1);
        build(mid+1,se,2*si+2);

        tree[si]=(tree[2*si+1]%m*tree[2*si+2]%m)%m;
    };

    build(0,n-1,0);
    // debug("hi");
    function<long long(long long,long long,long long,long long,long long)>query=[&](long long ss,long long se,long long qs,long long qe,long long si)->long long{

        if(qs>se || qe<ss)
        {
            return 1;
        }

        if(qs<=ss && qe>=se)
        return tree[si];

        long long mid=(ss+se)/2;

        long long y=(query(ss,mid,qs,qe,2*si+1)%m * query(mid+1,se,qs,qe,2*si+2)%m)%m;
        return y;
    };
    for(long long i=n-k-1;i>=0;i--)
    {
        long long p=query(0,n-1,i+1,i+k,0);
        // debug("hi");
        dp[i]=(arr[i]+(arr[i]%m*(dp[i+1]%m-p%m+m)%m)%m)%m;
    }
    for(long long i=0;i<n;i++)
    {
        res=(res%m+dp[i]%m)%m;
    }
    cout<<res<<endl;
}