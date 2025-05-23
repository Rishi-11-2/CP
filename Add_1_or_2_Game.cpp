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

    function<int(int,int)>f=[&](int i,int flag)->int{
        if(i>=n)
        {
            if(i==n)
            return 1;
            
            return 0;
        }

        int x=f(i+1,1-flag);
        int y=f(i+2,1-flag);
        if(flag==0)
        {
            if(x==0||y==0)
            return 0;
        }

        return 1;
    };

    int res=f(0,0);

    if(!res)
    cout<<"ALICE"<<endl;
    else
    cout<<"BOB"<<endl;
}