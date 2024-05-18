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
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];

    
    function<int(int,int,int)>f=[&](int i,int mex,int flag)->int{

        if(i==n)
       {
        //    debug(mex);
           return 1;
       }

        int res=f(i+1,mex,flag);
        if(arr[i]==mex-1)
        {
            if(flag==0)
            {
                res=res+f(i+1,mex,0);
            }
            else if(flag==1)
            {
                res=res+f(i+1,mex,1);
            }
        }
        if(arr[i]==mex)
        {
            if(flag==0)
            {
                res=res+f(i+1,mex+1,0);
            }
          
        }
        if(arr[i]==mex+1)
        {
            
            res=res+f(i+1,mex,1);
        }

        return res;
    };

    int x=f(0,0,0);
    vector<vector<int>>curr(n+1,vector<int>(2,0));
    vector<vector<int>>prev(n+1,vector<int>(2,1));
    for(int i=n-1;i>=0;i--)
    {
        for(int flag=1;flag>=0;flag--)
        {
            int res=prev[arr[i]][flag];
            
            if((arr[i]+1)<=n)
            {
                if(flag==0)
                {
                    res=res+prev[arr[i]+1][0];
                }
                else if(flag==1)
                {
                    res=res+prev[arr[i]+1][1];
                }
            }
            if((arr[i]+1)<=n)
            {
                if(flag==0)
                {
                    res=res+prev[arr[i]+1][0];
                }
                
            }
            if(arr[i]==mex+1)
            {
                
                res=res+prev[arr[i]-1][1];
            }
        }

    }
    cout<<x-1<<endl;
}