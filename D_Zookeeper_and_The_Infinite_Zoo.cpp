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
    int q;
    cin>>q;

    for(int j=1;j<=q;j++)
    {
        int a,b;
        cin>>a>>b;

       int flag=1;
       if(a>b)
       flag=0;
        
        int z=0;
        for(int i=0;i<30;i++)
        {
            if(a&(1<<i))
            z++;

            if(b&(1<<i))
            z--;

           if(z<0)
           {
              flag=0;
           }
        }
        /*Observe 0011 => 0101 => 1001, 0011 => 0100.
        There is no way that we can increase the number of 1s. And we can always promote a single 1 to higher bits or
         squish arbitrary 1s to a single 1.
Counting prefix sum of 1s (from lower bits to higher bits) in U and V, and we can not transform U to V if any prefix of U has fewer 1s compared to the prefix of V.*/

/* we cannot shift 1 to left. we can only shift to right as we are adding*/
        if(!flag)
        {
            cout<<"NO"<<endl;
        }
        else
        cout<<"YES"<<endl;
    }
}