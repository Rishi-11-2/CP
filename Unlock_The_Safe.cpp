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

    int a[n];

    for(int i=0;i<n;i++)
    cin>>a[i];

    int b[n];

    for(int i=0;i<n;i++)
    cin>>b[i];

    int c[n];

    vector<int>v;
    for(int i=0;i<n;i++)
    {
        c[i]=min(abs(a[i]-b[i]),(9-abs(a[i]-b[i])));
        // debug(i,c[i]);
        v.push_back(c[i]);
        k-=c[i];
    }

    // debug(k);
    if(k<0)
    {
        cout<<"No"<<endl;
        return;
    }

    if(k%2==0)
    {
        cout<<"Yes"<<endl;
        return;
    }
    

    sort(all(v));
    int i=n-1;
    // debug(k);
    while(i>=0)
    {
        int mx=9-v[i];
        // debug(i,v[i]);
        if((k+v[i])>=mx)
        {
            k+=v[i];
            k-=mx;
        }
        if(k%2==0)
        {
            cout<<"Yes"<<endl;
            return;
            // break;
        }
        if(k%9==0)
        {
            cout<<"Yes"<<endl;
            return;
        }
        i--;
    }

    cout<<"No"<<endl;
    
}