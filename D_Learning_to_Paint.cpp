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
    int n,k;
    cin>>n>>k;
    // vector<vector<int>>v;
    priority_queue<vector<int>>pq;

    vector<vector<int>>a;
    for(int i=1;i<=n;i++)
    {
        vector<int>x;
        for(int j=1;j<=n-i+1;j++)
        {
            int y;
            cin>>y;
            x.push_back(y);
        }
        a.push_back(x);
    }
    vector<vector<pair<int,int>>>v;
    for(int i=1;i<=n;i++)
    {
        vector<pair<int,int>>y;
        for(int j=1;j<=n-i+1;j++)
        {
            int x=a[j-1][i-1];
            y.push_back({x,j-1});
            
        }
        sort(all(y));
        reverse(all(y));
        if((int)(y.size())==1)
        {
            pq.push({y[0].first,i-1,y[0].second});
            continue;
        }
        if(y[0].second!=y[1].second)
        {
            pq.push({y[0].first+y[1].first,i-1,y[0].second});
        }
        else
        {
            pq.push({y[0].first+y[2].first,i-1,y[0].second});
        }
        v.push_back(y);
    }
    vector<int>res;
    while(k--)
    {
        auto it=pq.top();
        pq.pop();
        
    }
}