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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin>>n;
    vector<string>v;
    int maxm=0;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
        maxm=max(maxm,(int)s.length());
    }
    reverse(all(v));

    vector<vector<char>>ans(maxm+1,vector<char>(n+1,'/'));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<v[i].length();j++)
        {
            ans[j][i]=v[i][j];
        }
        for(int j=v[i].length();j<maxm;j++)
        {
            ans[j][i]='*';
        }
    }
    for(int i=0;i<maxm;i++)
    {
        string s;
        int idx=-1;
        for(int j=n-1;j>=0;j--)
        {
            if(ans[i][j]!='*')
            {
                idx=j;
                break;
            }
        }
        for(int j=0;j<=idx;j++)
        cout<<ans[i][j];
        cout<<endl;
    }
}