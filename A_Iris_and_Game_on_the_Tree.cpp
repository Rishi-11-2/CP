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
    int n;
    cin>>n;

    vector<int>indegree(n+1,0);
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        // debug(a,b);
        indegree[a]++;
        indegree[b]++;
    }
    int leaf_one=0;
    int leaf_zero=0;
    int in=0;
    int leaf_undecided=0;
    string s;
    cin>>s;

    for(int i=1;i<n;i++)
    {
        // debug(i,indegree[i]);
        if(indegree[i]==1)
        {
            // debug(i);
            if(s[i]=='1')
            leaf_one++;
            else if(s[i]=='0')
            leaf_zero++;
            else
            leaf_undecided++;
        }
        else if(s[i]=='?')
        {
            in++;
        }
    }
    // debug(leaf_one,leaf_zero,leaf_undecided);
    if(s[0]!='?')
    {
        if(s[0]=='1')
        {
            cout<<leaf_zero+(leaf_undecided+1)/2<<endl;
        }
        else
        {
            cout<<leaf_one+(leaf_undecided+1)/2<<endl;
        }
    }
    else
    {
        if(leaf_zero==leaf_one && (in%2))
        {
            cout<<leaf_zero+(leaf_undecided+1)/2<<endl;
        }
        else
        {
            cout<<max(leaf_one,leaf_zero)+(leaf_undecided/2)<<endl;
        }
    }
}