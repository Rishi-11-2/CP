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
int make_query(int l,int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    int codeforcesOutput;

    cin>>codeforcesOutput;

    return codeforcesOutput;
}
void solve()
{
    int n;
    cin>>n;

    int low=1;
    int high=n;

    while(high-low>=1)
    {
        int mid=(low+high)/2;

        int sI=make_query(low,high);
        int cI=-1;
        if(sI<high)
        cI=make_query(sI,high);
        else
        break;

        if(sI==cI)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    cout<<"! "<<low<<endl;
}