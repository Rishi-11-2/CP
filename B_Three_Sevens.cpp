#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
    map<int,int>m1;
    vector<vector<int>>v(n,vector<int>());
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        vector<int>x;
        for(int i=0;i<m;i++)
        {
            int y;
            cin>>y;
            m1[y]+=1;
            x.push_back(y);
        }
        v.push_back(x);
    }
    vector<int>res;
    int flag=0;
    for(auto &it:v)
    {
        flag=0;
        for(auto &i:it)
        {
            m1[i]--;
            if(m1[i]==0)
            {
                if(flag==0)
                {
                    flag=1;
                    res.push_back(i);
                }
            }
        }
    }
    // for(int i=0;i<n-1;i++)
    // {
    //     auto a=v[i];
    //     auto b=v[i+1];
    //     int n=a.size();
    //     int m=b.size();
    //     if(n==m)
    //     {
    //         int pl=0;
    //         for(int i=0;i<n;i++)
    //         {
    //             if(a[i]==b[i])
    //             {
    //                 pl++;
    //             }

    //         }
    //         if(pl==n)
    //         {
    //             cout<<-1<<endl;
    //             return;
    //         }
    //     }
    // }
    if(res.size()!=n)
    {
        cout<<-1<<endl;
        return;
    }
    for(auto &it:res)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}