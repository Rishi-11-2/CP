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
//(data type to be stored (pair,long long ,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong long s)
typedef tree < pair<long long ,long long >, null_type,less<pair<long long ,long long >>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long  t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
     long long  n;
    cin >> n;
    long long  arr[n ];
    for (long long  i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr,arr+n);

    reverse(arr,arr+n);
    vector<long long >v;
    for(long long  i=0;i<n;i++)
    v.push_back(arr[i]);
    long long  x=v[0];

    // vector<long long >vv;
    vector<long long >res;
    while(1)
    {
        long long  flag=0;
        vector<long long >vv;
        for(long long  i=0;i<n;i++)
        {
            if(v[i]!=-1 && (v[i]&x)==x)
            {
                vv.push_back(x);
                v[i]=-1;
                flag=1;
            }
        }
        long long  y=0;
        for(long long  i=0;i<n;i++)
        {
            if(v[i]==-1)
            continue;
            y=max(y,x&v[i]);
        }
        x=y;
        // debug(x);
        for(auto it:vv)
        {
            res.push_back(it);
        }
        if(!flag)
        break;
    }

    for(auto it:res)
    cout<<it<<" ";
    cout<<endl;

}