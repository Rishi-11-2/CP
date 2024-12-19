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
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin>>n;

    int arr[n+1];

    for(int i=1;i<=n;i++)
    cin>>arr[i];
    

    function<int(int)>check=[&](int i)->int{

        if(i==(n-i+1))
        return 0;
        int count1=0;
        int count2=0;
        if(i>1)
        {
            if(arr[i]==arr[i-1])
            count1++;
        }
        if(i<n)
        {
            if(arr[i]==arr[i+1])
            count1++;
        }
        int j=n-i+1;
        if(j>1)
        {
            if(arr[i]==arr[j-1])
            count2++;
        }
        if(j<(n))
        {
            if(arr[i]==arr[j+1])
            count2++;
        }
        if(count2<count1)
        return 1;

        return 0;
    };
    for(int i=1;i<=n;i++)
    {
        if(check(i))
        {
            // debug(i,n-i+1);
            swap(arr[i],arr[n-i+1]);
        }
    }

    int ans=0;
    for(int i=1;(i+1)<=n;i++)
    {
        if(arr[i]==arr[i+1])
        ans++;
    }
    cout<<ans<<endl;
}