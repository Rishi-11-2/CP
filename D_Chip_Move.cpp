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
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int>dp(n+1,-1);
    function<int(int,int)>f=[&](int i,int x)->int{

        if(i>n)
        return 0;

        if(i==n)
        return 1;
        
        if(dp[i]!=-1)
        return dp[i];
        int res=0;
        int  j=k+x;
        while(j<n)
        {
            res=res+f(i+j,x+1);
            j+=(k+x);
        }

        return dp[i]= res;
    };

    int x=f(0,0);
    cout<<x<<endl;
    for(int i=1;i<=n;i++)
    cout<<dp[i]<<" ";
    cout<<endl;
}