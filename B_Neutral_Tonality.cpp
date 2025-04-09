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
    int n,m;
    cin>>n>>m;

    int a[n];

    set<int>s;  
    for(int i=0;i<n;i++)
    cin>>a[i];

    int b[m];

    for(int i=0;i<m;i++)
    cin>>b[i];

    sort(b,b+m);

    reverse(b,b+m);

    int j=m-1;

    int k=0;

   int maxm=*max_element(a,a+n);

   vector<int>v1;
   while(k<m && b[k]>=maxm)
   {
       v1.push_back(b[k]);
       k++;
    }
    vector<int>v;

    int i=n-1;


    while(i>=0)
    {
        while((j>=k)  && (b[j]<=a[i]))
        {
            v.push_back(b[j]);
            j--;
        }
        v.push_back(a[i]);
        i--;
    }
    
    reverse(all(v));
    // while(j<m)
    for(auto it:v1)
    {
        cout<<it<<" ";
    }
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    cout<<endl;

}