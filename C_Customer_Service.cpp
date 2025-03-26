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

    vector<vector<int>>arr(n,vector<int>(n));

    vector<int>suffix(n+1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            suffix[i]++;
        }
        
    }
    int low=0;
    int high=(n);

    function<int(int)>f=[&](int mid)->int{
        int x=mid;
        debug(mid);
        for(int j=0;j<n;j++)
        {
            int flag=1;
            for(int i=0;i<n;i++)
            {
                suffix[i]-=arr[i][j];
                int s=suffix[i];
                if(s==x && flag==1)
                {
                    flag=0;
                    x--;
                    // break;
                }
            }
        }
        if(x==0)
        return 1;

        return 0;
    };
    int res=0;
    while(low<=high)
    {
        int mid=(low+high)/2;

        if(f(mid))
        {
            low=mid+1;
            res=mid;
        }
        else
        {
            high=mid-1;
        }
    }

    cout<<res<<endl;
}