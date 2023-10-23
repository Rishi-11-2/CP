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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,k,z;
    cin>>n>>k>>z;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i]; 

    vector<vector<int>>dp(n+1,vector<int>(z+1,-1));
    function<int(int,int,int,int)>f=[&](int i,int z,int c,int flag)->int{
            if(c==k)
            return 0;
            if(i<0 || i>(n-1) || z<0)
            return -0x3f3f3f3f;
            if(dp[i][z]!=-1)
            return dp[i][z];
            int x1=0;
            if(flag==0)
            {
                // cout<<"ho"<<endl;
                x1=f(i-1,z-1,c+1,1-flag);
                
            }
            if(flag==1)
            flag=0;
        int x2=f(i+1,z,c+1,flag);
        return dp[i][z]=max(x1,x2)+arr[i];
    };
    cout<<f(1,z,0,0)+arr[0]<<endl;
}