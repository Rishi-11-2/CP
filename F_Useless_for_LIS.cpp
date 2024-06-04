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
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];

    vector<int>s;
    vector<int>e;

    vector<int>a(n,0);
    vector<int>b(n,0);
    for(int i=0;i<n;i++)
    {
        if(s.empty() || arr[i]>s.back())
        {
            s.push_back(arr[i]);
            a[i]=(int)(s.size());
        }
        else
        {
            int j=lower_bound(s.begin(),s.end(),arr[i])-s.begin();
            s[j]=arr[i];
            a[i]=j+1;
        }
    }
    int l=(int)(s.size());
    for(int i=n-1;i>=0;i--)
    {
        if(e.empty() || -arr[i]>e.back())
        {
            e.push_back(-arr[i]);
            b[i]=(int)(e.size());
        }
        else
        {
            int j=lower_bound(e.begin(),e.end(),-arr[i])-e.begin();
            e[j]=-arr[i];
            b[i]=j+1;
        }
    }

    vector<int>res;
    for(int i=0;i<n;i++)
    {
        if(a[i]+b[i]==l+1)
        {
            res.push_back(i);
        }
    }
    cout<<(int)(res.size())<<endl;
    for(auto it:res)
    {
        cout<<it+1<<" ";
    }
    cout<<endl;
}