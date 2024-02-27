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
    long long arr[n];
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    map<long long,long long>mp;
    long long r=n-1;
    long long flag=0;
    vector<long long>idx(n,0);
    vector<pair<long long,long long>>v;
    set<long long>s;
    s.insert(arr[n-1]);
    for(long long i=n-2;i>=0;i--)
    {
        
        if(s.find(arr[i])!=s.end())
        {
            idx[i]=1;
            s.clear();
        }
        else
        {
            s.insert(arr[i]);
            idx[i]=idx[i+1];
        }
    }
    flag=0;
    s.clear();
    r=0;
    for(long long i=0;i<n;i++)
    {
        if(s.find(arr[i])!=s.end())
        {
            if(idx[i]==1)
            {
              v.push_back({r,i});
              r=i+1;
            }
            else
            {
                v.push_back({r,n-1});
                i=n;
                r=n;
            }   
            s.clear();
        }
        else
        s.insert(arr[i]);
    }
    if((int)(v.size())==0)
    {
        cout<<-1<<endl;
        return;
    }
    else
    {
        if(r<n)
        {
            v[(int)(v.size())-1].second=n-1;
        }
    }
    cout<<(long long)(v.size())<<endl;
    // reverse(all(v));
    for(auto it:v)
    {
        cout<<it.first+1<<" "<<it.second+1<<endl;
    }

}