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
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<vector<vector<vector<int>>>>dp(n+1,vector<vector<vector<int>>>(m+1,vector<vector<int>>(n+1,vector<int>(m+1,-1))));
        function<long long(long long,long long,long long,long long)>f=[&](long long i,long long j,long long dx,long long dy)->long long{
            debug(i,j,dx,dy);
            if(dx==1 && dy==1)
            {
                return 0;
            }
            if(i==0 && j==4 && dx==3 && dy==2)
            debug("hi");
            long long res=(long long)(1e12);
            for(long long k=0;k<dx-1;k++)
            {
                res=min(res,f(i,j,k+1,dy)+f(k+1,j,dx-(k+1),dy)+verticalCut[k+i]);
            }
            for(long long k=0;k<dy-1;k++)
            {
                // cout<<dy<<" "<<k+1<<endl;
                res=min(res,f(i,j,dx,k+1)+f(i,k+1,dx,dy-(k+1))+horizontalCut[k+j]);
            }
            return res;
        };

        long long ans=f(0,0,n,m);
        return ans;
    }
void solve()
{
    int m,n;
    cin>>m>>n;
    vector<int>h;
    for(int i=0;i<m-1;i++)
    {
        int x;
        cin>>x;
        h.push_back(x);
    }
    vector<int>v;
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<minimumCost(m,n,h,v)<<endl;

}