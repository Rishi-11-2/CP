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
    int t;
    // cin >> t;
    // while (t--)
     solve();

}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    // if(n==1)
    // {
    //     cout<<0<<endl;
    //     cout<<arr[0]<<endl;
    //     return;
    // }
    int low=0;
    int high=n;
    int res=low;
    function<int(int)>f=[&](int mid)->int{
        int i=0;
        int count=0;
        int j=mid;
        while(j<n-1)
        {
            if(arr[j]>arr[i])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if(count>=mid)
        return 1;
        return 0;
    };
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(f(mid))
        {
            res=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<res<<endl;
    int j=0;
    int k=n-res-1;
    // debug(k);
    for(int i=0;i<n;i++)
    {
        if(i%2==0 && k<n)
        {
            // debug(k);
            cout<<arr[k]<<" ";
            k++;
        }
        else if(j<res){
            // debug(j);
            cout<<arr[j]<<" ";
            j++;
        }
    }
    while(j<(n-res-1))
    {
        cout<<arr[j]<<" ";
        j++;
    }
    cout<<endl;
}