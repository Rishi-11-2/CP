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
    int n;
    cin>>n;
    int m[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>m[i][j];
    }
    set<int>s;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        int x=m[i][(i+1)%n];
        for(int j=0;j<n;j++)
        {
            if(j==i|| j==(i+1)%n)
            continue;
            
            x=x&m[i][j];
        }
        
        res.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            continue;
            if((res[i]|res[j])!=m[i][j])
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    for(auto it:res)
    cout<<it<<" ";
    cout<<endl;
} 