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
    int n,s,m,l;
    cin>>n>>s>>m>>l;
    map<int,int>mp;
    function<int(int)>f=[&](int i)->int{

        if(i<=0)
        return 0;
        if(mp.find(i)!=mp.end())
        return mp[i];
        int x=f(i-6)+s;
        int y=f(i-8)+m;
        int z=f(i-12)+l;
        int res=min({x,y,z});

        return mp[i]= res;
    };

    int x=f(n);

    cout<<x<<endl;
}