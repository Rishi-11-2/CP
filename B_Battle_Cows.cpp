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
    int n,idx;
    cin>>n>>idx;
    int a[n];
    idx--;
    int target;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==idx)
        {
            target=a[i];
        }
    }

    int maxm=*max_element(a,a+n);
    if(maxm==target)
    {
        cout<<n-1<<endl;
        return;
    }
    int x=0;
    int res=0;
    int flag=0;
    int flag1=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<target)
        {
            x++;
        }
        if(a[i]==target)
        {
            if(flag1==1)
            {
                res=max(res,x);
                break;
            }
            flag=1;
        }
        if(a[i]>target)
        {
            if(flag||flag1)
            {
                res=max(res,x);
                break;
            }
            else
            {
                res=max(res,x-1);
                x=min(x,1);
                flag1=1;
            }
        }
    }
    cout<<res<<endl;
}