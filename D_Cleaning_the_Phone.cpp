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

    long long a[n],b[n];
    long long cc=0;
    long long ss=0;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        ss+=a[i];
    }
    for(long long i=0;i<n;i++)
    {
        cin>>b[i];
        cc+=b[i];
    }
    if(ss<m)
    {
        cout<<-1<<endl;
        return;
    }
    vector<pair<long long,long long>>one;
    vector<pair<long long,long long>>two;

   
    for(long long i=0;i<n;i++)
    {
        if(b[i]==1)
        {
            one.push_back({a[i],b[i]});
        }
        else if(b[i]==2)
        {
            two.push_back({a[i],b[i]});
        }
    }

    sort(all(one));
    sort(all(two));


    long long low=0;

    long long high=(long long)(1e16);

    // for(auto it:v)
    // {
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    function<long long(long long)>f=[&](long long mid)->long long{

      
        long long s1=ss;
        long long c1=cc;
        for(auto it :one)
        {
            if((s1-it.first)>=m)
            {
                s1-=it.first;
                c1-=it.second;
            }

        }
        for(auto it:two)
        {
            if((s1-it.first)>=m)
            {
                s1-=it.first;
                c1-=it.second;
            }
        }

        long long s2=ss;
        long long c2=cc;

        for(auto it :two)
        {
            if((s2-it.first)>=m)
            {
                s2-=it.first;
                c2-=it.second;
            }

        }
        for(auto it:one)
        {
            if((s2-it.first)>=m)
            {
                s2-=it.first;
                c2-=it.second;
            }
        }

        long long c3=min(c1,c2);

        if(c3<=mid)
        return 1;
        return 0;
        
        
    };
    // cout<<f(1)<<endl;
    long long res=-1;
    while(low<=high)
    {
        long long mid=(low+high)/2;
        if(f(mid))
        {
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<res<<endl;
}