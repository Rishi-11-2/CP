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
    int a[m];
    for(int i=0;i<m;i++)
    cin>>a[i];
    vector<string>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<vector<int>>x;
    int maxm=0;
    vector<int>score(n,0);
    for(int i=0;i<n;i++)
    {
        int sc=0;
        vector<int>y;
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='o')
            {
                sc+=a[j];
            }
            else if(v[i][j]=='x')
            {
                y.push_back(a[j]);
            }
        }
        maxm=max(maxm,sc+i+1);
        score[i]=sc+i+1;
        sort(all(y),greater<int>());
        x.push_back(y);
    }
    // cout<<"Hi"<<endl;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        if(score[i]==maxm)
        {
            res.push_back(0);
        }
        else
        {
            int count=0;
            int sc=score[i];
            for(auto it:x[i])
            {
                sc=sc+it;
                count++;
                if(sc>maxm)
                {
                    break;
                }
            }
           res.push_back(count);
        }
    }
    for(auto it:res)
    cout<<it<<endl;
}