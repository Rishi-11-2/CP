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
    int n,x;
    cin>>n>>x;

    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];

    sort(arr,arr+n);

    reverse(arr,arr+n);

    int count=0;

    int i=0;
    while(i<n)
    {
        int minm=arr[i];
        int j=i;
        while(j<n)
        {
            minm=min(minm,arr[j]);
            int len=(j-i+1);
            int y=len*minm;
            if(y>=x)
            {
                count++;
                break;
            }
            j++;
        }
        i=j+1;
    }
    cout<<count<<endl;
}