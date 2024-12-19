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
    int n,k;
    cin>>n>>k;

    if(n==1)
    {
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }

    if(k==n)
    {
        cout<<-1<<endl;
        return;
    }

    int left=k-1;

    int right=n-k;

    // debug(left,right);
    if(left%2 && right%2)
    {
        cout<<3<<endl;
        cout<<1<<" "<<k<<" "<<k+1<<endl;
        return;
    }
    vector<int>v;
    int flag=0;
    v.push_back(1);
    for(int i=1;i<left;i++)
    {
        if(i%2 && (left-i)%2)
        {
            flag=1;
            v.push_back(i+1);
            break;
        }
    }
    if(flag==0)
    {
        cout<<-1<<endl;
        return;
    }
    flag=0;
    v.push_back(k);
    for(int i=1;i<right;i++)
    {
        if(i%2 && (right-i)%2)
        {
            flag=1;
            v.push_back(i+k);
            v.push_back(i+k+1);
            break;
        }
    }
    if(flag==0)
    {
        cout<<-1<<endl;
        return;
    }

    cout<<5<<endl;
    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;
}