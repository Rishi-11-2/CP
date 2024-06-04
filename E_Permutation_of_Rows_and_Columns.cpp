#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    int n,m;
    cin>>n>>m;

    int matrix[n][m];
    int matrix2[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>matrix[i][j];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>matrix2[i][j];
    }
    if(n==1 || m==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    map<vector<int>,int>rows;
    map<vector<int>,int>rrows;

    for(int i=0;i<n;i++)
    {
        vector<int>v;
        for(int j=0;j<m;j++)
        {
            v.push_back(matrix[i][j]);
        }
        rows[v]+=1;
        rrows[v]+=1;
    }
    for(int i=0;i<n;i++)
    {
        vector<int>v;
        for(int j=0;j<m;j++)
        {
            v.push_back(matrix2[i][j]);
        }
        rows[v]-=1;
        if(rows[v]==0)
        rows.erase(v);
    }

    map<vector<int>,int>cols;
    for(int i=0;i<m;i++)
    {
        vector<int>v;
        for(int j=0;j<n;j++)
        {
            v.push_back(matrix[j][i]);
        }
        // for(auto it:v)
        // cout<<it<<" ";
        // cout<<endl;
        cols[v]+=1;
    }
    for(int i=0;i<m;i++)
    {
        vector<int>v;
        for(int j=0;j<n;j++)
        {
            v.push_back(matrix2[j][i]);
        }
        cols[v]-=1;
        if(cols[v]==0)
        cols.erase(v);
    }


    if((int)(rows.size())==0 || (int)(cols.size())==0)
    {
        cout<<"YES"<<endl;
        
    }
    else
    {
        cout<<"NO"<<endl;
    }
}