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
    long long n;
    cin>>n;
    long long arr[n];
    vector<long long>f(n+1,0);
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        f[arr[i]]=1;
    }
    long long mex=0;
    while(f[mex])
    {
        mex++;
    }
    if(mex==0)
    {
        cout<<n<<endl;
        for(long long i=0;i<n;i++)
        {
            cout<<i+1<<" "<<i+1<<endl;
        }
        return;
    }
    vector<pair<long long,long long>>v;
    // vector<long long>f2(n+1,0);
    set<long long>s;
    long long i=0;
    long long j=i;
    for(long long i=0;i<mex;i++)
    s.insert(i);
        while(i<n)
        {
            if((long long)(s.size())==0)
            break;
            if(s.find(arr[i])!=s.end())
            s.erase(arr[i]);
            
            i++;
        }
            // debug(j,i);
        if((long long)s.size()==0)
        v.push_back({j,i-1});
        j=i;
        for(long long i=0;i<mex;i++)
        s.insert(i);
        while(i<n)
        {
            if(s.find(arr[i])!=s.end())
            s.erase(arr[i]);
            i++;
        }

        if((long long)s.size()==0)
        {
             v.push_back({j,i-1});
        }
        else
        {
            cout<<-1<<endl;
            return;
        }


    long long sz=(long long)(v.size());

    if(sz<=1)
    {
      cout<<-1<<endl;
    }
    else
    {
        cout<<sz<<endl;
        for(auto it:v)
        cout<<it.first+1<<" "<<it.second+1<<endl;
        // cout<<endl;
    }
}