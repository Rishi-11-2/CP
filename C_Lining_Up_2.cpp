#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
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
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    vector<int>v(n+1,-1);
    int start=-1;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==-1)
        {
            start=i;
        }
        else
        {
            v[arr[i]]=i;
        }
    }
    // for(auto it:v)
    // cout<<it<<" ";
    // cout<<endl;
    int i=start;
    vector<int>res;
    while(i!=-1)
    {
        res.push_back(i);
        i=v[i];
    }
    for(auto it:res)
    cout<<it<<" ";
    cout<<endl;
}