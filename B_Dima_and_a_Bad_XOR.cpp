#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    solve();
}
void solve()
{
    long long n,m;
    cin>>n>>m;
    // vector<vector<long long>>dp(n,vector<long long>(1025,0));
   vector<vector<int>>a(n,vector<int>(m,0));
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        cin>>a[i][j];
    }
    vector<vector<int>>dp(n+1,vector<int>(1024,-1));
    vector<int>path;
    // int flag=0;
    function<int(int,int,vector<int>)>f=[&](int i,int xorr,vector<int>xx)->int{
        if(i==n)
        {
            if(xorr>0)
            {
                path=xx;
                return 1;
            }
            return 0;
        }
        if(dp[i][xorr]!=-1)
        return dp[i][xorr];
        int res=0;
        for(int j=0;j<m;j++)
        {
            xx.push_back(j+1);
            int nxorr=xorr xor a[i][j];
            res=res||f(i+1,nxorr,xx);
            xx.pop_back();
        }
        return dp[i][xorr]=res;
    };
    vector<int>x;
    int res=f(0,0,x);
    if(res)
    {
        cout<<"TAK"<<endl;
        for(auto it:path)
        cout<<it<<" ";
        cout<<endl;
        return;
    }
    cout<<"NIE"<<endl;
}
