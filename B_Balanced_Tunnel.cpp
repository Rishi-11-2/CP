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
void solve()
{
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    for(int i=0;i<n;i++)
    cin>>b[i];
     
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]=i;
    }

    int i=0;
    int j=0;
    int count=0;
    while(i<n)
    {
        if(a[i]==0)
        {
            i++;
            continue;
        }
        if(a[i]==b[j])
        {
            i++;
            j++;
        }
        else
        {
            count++;
            a[mp[b[j]]]=0;
            j++;
        }
    }

    cout<<count<<endl;
     
    
}