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
    int n,m;
    cin>>n>>m;
    vector<int>a(n,vector<int>(m,0));
    vector<int>b(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>b[i][j];
    }

    function<int(int,vector<vector<int>>)>f=[&](int i,vector<vector<int>>a)->int{
        if(i==n)
        return 0;
        
        

    };
}