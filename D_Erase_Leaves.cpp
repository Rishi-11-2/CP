#include <bits/stdc++.h>
using namespace std;
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
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
    int n;
    cin>>n;
    vector<int>adj[n+1];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // if((int)adj[1].size()<=1)
    // {
    //     cout<<1<<endl;
    //     return;
    // }
    function<int(int,int)>f=[&](int u,int p)->int{
        // int flag=0;
        int res=0;
        for(int v:adj[u])
        {
            if(v!=p)
            {
                res=res+f(v,u);
            }
        }
        return 1+res;
    };
    int s=0;
    vector<int>v;
    for(int u:adj[1])
    {
        int x=f(u,1);
        v.push_back(x);
        s+=x;
    }
    int res=s-*max_element(all(v));
    cout<<1+res<<endl;
}