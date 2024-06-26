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
    int n,q;
    cin>>n>>q;
    vector<int>arr;
    arr.push_back(0);
    vector<int>op(n+1,0);
    int k=-1;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int y;
            cin>>y;
            k++;
            arr.push_back(y);
        }
        else
        {
            int y;
            cin>>y;
            op[k]+=y;
        }
    }

    int q;
    cin>>q;
    vector<int>queries;
    for(int i=1;i<=q;i++)
    {
        int x;
        cin>>x;
        queries.push_back(x);
    }
    sort(all(queries));
    int len=0;
    for(int i=1;i<(int)(arr.size());i++)
    {
        if(op[i]>0)
        {
            len=i;
            break;
        }
    }
    int l=0;
    vector<int>res;
    for(int i=0;i<q;i++)
    {
        if((queries[i]-l)>len)
        {
            l+=len;
        }
        else
        {
            res.push_back(arr[queries[i]-l]);
        }
    }
}