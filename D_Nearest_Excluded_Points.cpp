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

}
void solve()
{
    int n;
    cin>>n;

    vector<pair<int,int>>v;

    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;

        v.push_back({x,y});
    }

    priority_queue< pair<int, pair<int,int>> , vector< pair<int, pair<int,int>> > , greater< pair<int, pair<int,int>> > >pq;

    map<pair<int,int>,int>dp;
    for(auto it:v)
    {
        pq.push({0,it});
        dp[it]=0;
    }

    while(!pq.empty())
    {
        auto it=pq.top();

        pq.pop();

        int d=it.first;

        int i=it.second.first;
        int j=it.second.second;

        int a[]={-1,1,0,0};
        int b[]={0,0,-1,1};

        for(int k=0;k<4;k++)
        {
            int x=a[k]+i;
            int y=b[k]+j;
            
            if(dp.find({x,y})!=dp.end())
            {
                
            }
            
        }
    }
}