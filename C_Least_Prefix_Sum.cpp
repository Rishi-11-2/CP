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
#define nline "\n" 
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
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    long long sum=0;
    long long count=0;
    multiset<long long>s;
        for(long long i=m-1;i>0;i--)
        {
            sum+=a[i];
            s.insert(a[i]);
            // debug(i);
            while(sum>0)
            {
                // debug(sum);
                auto it=*s.rbegin();
                sum-=it;
                sum-=it;
                count++;
                s.insert(-(it));
                s.erase(s.find(it));
            }
        }
    // debug(sum);
    s.clear();
    // debug(count);
    // s.insert(a[m-1]);
    sum=0;
    for(long long i=m;i<n;i++)
    {
        sum+=a[i];
        s.insert(a[i]);
        // prefixes.insert(sum);
        while(sum<0)
        {
            auto it=*s.begin();
            sum-=it;
            sum-=it;
            count++;
            s.insert(-(it));
            s.erase(s.find(it));
            
        }
        // s.insert(sum);
    }
    cout<<count<<endl;

}