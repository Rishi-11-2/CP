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
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        v.push_back(arr[i]);
    }
    

    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    function<int(int,vector<int>)>f=[&](int k,vector<int>v)->int{
        

        if(k==0)
        {
            int s=0;
            for(int i=0;i<n;i++)
            {
                s+=v[i];

            }
            return s;
        }
        int res=f(k,v);
         for(int i=0;i<n;i++)
         {
            if(i+1<n && v[i]>v[i+1])
            {
                v[i]=v[i+1];
                res=min(res,f(k-1,v));
            }
            if(i-1>=0 && v[i]>v[i-1])
            {
                v[i]=v[i-1];
                res=min(res,f(k-1,v));
            }
         }

         return res;
    };

    int x=f(k,v);


    cout<<x<<endl;

}