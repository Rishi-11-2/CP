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
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
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
    int n,k;
    cin>>n>>k;
    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];
    if(k==1)
    {
        cout<<*min_element(arr,arr+n)<<endl;
    }
    else if(k>2)
    {
        cout<<*max_element(arr,arr+n)<<endl;
    }
    else
    {
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        prefix[0]=arr[0];
        suffix[n-1]=arr[n-1];

        for(int i=1;i<n;i++)
        {
            prefix[i]=min(prefix[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=min(suffix[i+1],arr[i]);
        }
        
        int res=max({prefix[1],suffix[n-2],arr[0],arr[n-1]});

        for(int i=1;i<n-1;i++)
        {
            res=max({res,prefix[i-1],suffix[i]});
        }

        cout<<res<<endl;
    }
}