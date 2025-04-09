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
    long long q;
    cin>>q;

    
    const long long n=(long long)(1e6);
    vector<long long>isPrime(n+1,1);
    vector<long long>count(n+1,0);
    isPrime[0]=isPrime[1]=0;

    vector<long long>primes;
    
    for(long long i=2;i<=n;i++)
    {
        if(isPrime[i]==1)
        {
            for(long long j=2*i;j<=n;j+=i)
            {
                isPrime[j]=0;
                count[j]++;
            }
        }
    }
    

    for(long long i=2;i<=n;i++)
    {
        if(count[i]==2)
        {
            primes.push_back(i*i);
        }
    }


    vector<pair<long long,long long>>queries;
    for(long long i=0;i<q;i++)
    {
        long long x;
        cin>>x;
        queries.push_back({x,i});
    }
    // debug(primes[(long long)primes.size()-1]);

    
    vector<long long>ans(q);
    sort(all(queries));
    reverse(all(queries));
    reverse(all(primes));
    // for(long long i=0;i<sz;i++)
    // cout<<v[i]<<" ";
    // cout<<endl;

    long long sz=(long long)primes.size();
    long long i=0;
    long long j=0;
    while(j<q)
    {
        while((i<sz) && (queries[j].first<primes[i]))
        {
            i++;
        }
        ans[queries[j].second]=primes[i];
        j++;
    }

    for(auto it:ans)
    cout<<it<<endl;

}