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
    long long n,q;
    cin>>n>>q;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    vector<long long>ones(n,0);
    vector<long long>notOnes(n,0);
    ones[0]=(arr[0]==1)?1:0;
    notOnes[0]=(arr[0]!=1)?arr[0]-1:0;
    for(long long i=1;i<n;i++)
    {
        if(arr[i]==1)
        {
            ones[i]=1+ones[i-1];
            notOnes[i]=notOnes[i-1];
        }
        else if(arr[i]!=1)
        {
            notOnes[i]=notOnes[i-1]+arr[i]-1;
            ones[i]=ones[i-1];
        }
    }


    for(long long i=1;i<=q;i++)
    {
        long long l,r;
        cin>>l>>r;
        r--;
        l--;
        if(l==r)
        {
            cout << "NO" << endl;
            continue;
        }
        long long x=notOnes[r];
        if(l>0)
        x-=notOnes[l-1];
        long long y=ones[r];
        if(l>0)
        {
            y-=ones[l-1];
        }

        if(x>=y)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}