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
int check(int n)
{
    if(n>=1 && n<=99)
    {
        return 1;
    }
    else if(n>=100 && n<=199)
    {
        return 2;
    }
    else if(n>=200 && n<=299)
    {
        return 3;
    }
    else if(n>=300 && n<=399)
    {
        return 4;
    }
}
void solve()
{
    int n;
    cin>>n;

    int count =check(n);

    int k=n+1;
    while(1)
    {
        int c=check(k);
        if(c>count)
        break;
        k++;
    }
    cout<<k-n<<endl;
}