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
   long long n,k,q;
    cin>>n>>k>>q;

    long long a[k+1];
    long long b[k+1];

    a[0]=0;
    b[0]=0;
    for(long long i=1;i<=k;i++)
    cin>>a[i];

    for(long long i=1;i<=k;i++)
    cin>>b[i];

    
    vector<long long>speeds;
    
    vector<pair<long long,long long>>query;

    for(long long i=0;i<q;i++)
    {
        long long x;
        cin>>x;
        query.push_back({x,i});
    }
    sort(all(query));

    long long i=1;
    long long j=0;
    long long  s=0;
    vector<long long>res(q);
    // cout<<"hi"<<endl;
    while(i<=k && j<q)
    {
        if(query[j].first<=a[i])
        {
            long long  c=query[j].first;
            if(j>0)
            {
                c-=query[j-1].first;
            }
            long long yy=(b[i]-b[i-1]);
            long long zz=(a[i]-a[i-1]);

            long long rr=c*yy;
            rr=rr/zz;
            s+=rr;
            // long long aa=(long long)(s);
            res[query[j].second]=s;
            // debug(s,aa);
            j++;
        }
        else
        {
            i++;
        }
    }
    
    for(auto it:res)
    cout<<it<<" ";
    cout<<endl;
}