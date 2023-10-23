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
    int m;
    cin>>m;
    vector<vector<char>>grid(2,vector<char>(m,'/'));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    int flag=-1;// 1 for 1st configuration 'B' and 'W'
    // 2 for 2nd configuration 'W' and 'B'
    int count=0;
    for(int i=0;i<m;i++)
    {
        // cout<<count<<endl;
        if(grid[0][i]=='B' && grid[1][i]=='W')
        {
            if(flag==-1)
            {
                flag=1;
                count=0;
            }
            else if(count%2 && flag==1)
            {
                cout<<"NO"<<endl;
                return;
            }
            else if(count%2==0 && flag==2)
            {
                cout<<"NO"<<endl;
                return;
            }
            else if(flag!=1)
            {
                flag=1;
                count=0;
            }
        }
        else if(grid[0][i]=='W' && grid[1][i]=='B')
        {
            if(flag==-1)
            {
                flag=2;
                count=0;
            }
            else if(count%2 && flag==2)
            {
                cout<<"NO"<<endl;
                return;
            }
            else if(count%2==0 && flag==1)
            {
                cout<<"NO"<<endl;
                return;
            }
            else if(flag!=2)
            {
                flag=2;
                count=0;
            }
        }
        else if(flag!=-1)
        count++;
    }
    cout<<"YES"<<endl;
}