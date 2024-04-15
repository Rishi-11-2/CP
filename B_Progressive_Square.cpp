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
    int n,c,d;
    cin>>n>>c>>d;

    vector<int>v;

    multiset<int>s;
    for(int i=1;i<=(n*n);i++)
    {
        int x;
        cin>>x;
        s.insert(x);
        v.push_back(x);
    }

    sort(all(v));

    vector<vector<int>>matrix(n,vector<int>(n,1));

    matrix[0][0]=v[0];

    for(int i=1;i<n;i++)
    {
        int f=matrix[0][i-1]+d;
        auto it=s.find(f);
        if(it==s.end())
        {
            cout<<"NO"<<endl;
            return;
        }
        matrix[0][i]=*it;
        s.erase(it);
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int f=matrix[i-1][j]+c;
            auto it=s.find(f);
            if(it==s.end())
            {
                cout<<"NO"<<endl;
                return;
            }
            matrix[i][j]=*it;
            s.erase(it);
        }
    }
    cout<<"YES"<<endl;

}