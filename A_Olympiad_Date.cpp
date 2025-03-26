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

    vector<int>f(10,0);

    f[0]=3;
    f[1]=1;
    f[2]=2;
    f[3]=1;
    f[5]=1;

    int n;
    cin>>n;

    int res=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;

        f[x]--;
        int flag=1;
        for(int j=0;j<10;j++)
        {
            if(f[j]>0)
            flag=0;
        }
        if(flag)
        res=min(res,i+1);
    }
    if(res==INT_MAX)
    res=0;
    cout<<res<<endl;

}