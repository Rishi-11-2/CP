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
int f(int mex,vector<int>&arr,int k)
{
    int count=0;
    int n=(int)arr.size();
    unordered_set<int>s;

    int res=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=(n+10))
        s.insert(arr[i]);
        while(s.count(res))
        {
            res++;
        }
        if(res>=mex)
        {
            for(int j=0;j<res;j++)
            s.erase(j);
            count++;
            res=0;
        }
        // debug(i,res,count,mex);
    }
    if(count>=k)
    return 1;

    return 0;
}
void solve()
{
    int n,k;
    cin>>n>>k;

    vector<int>arr(n);

    int high=(n/k);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }


    int low=0;

    int res=0;
    // debug(f(3,f));
    while(low<=high)
    {
        int mid=(low+high)/2;
        // debug(mid,f(mid,f));
        if(f(mid,arr,k))
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
}