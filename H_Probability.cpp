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
    cout.precision(15);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr;
    arr.push_back(0);

    int xcount=0;
    for(int i=1;i<=n;i++)
    {
        int x=0;
        cin>>x;
        if(x==i)
        xcount++;
        arr.push_back(x);
    }
    vector<pair<int,long double>>v;

    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        long double d;
        cin>>d;

        v.push_back({x,d});
    }
    sort(all(v));

    long double one=1;
    if(xcount==n)
    {
        cout<<one<<endl;
        return;
    }
    int idx=n;
    for(int i=n;i>=1;i--)
    {
        if(arr[i]==i)
        {
            idx--;
        }
        else
        break;
    }
    int flag=0;
    long double res=0.00;
    long double p=1.000;
    for(int i=0;i<m;i++)
    {
        
        if(v[i].first>=idx)
        {
            res=res+p*v[i].second;
            flag =1;
        }
        if(flag)
        {
            p=p*(1-v[i].second);
        }
    }

    cout<<res<<endl;
}