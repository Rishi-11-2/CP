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
    // cin >> t;
        solve();
}
void solve()
{
    int n;
    cin>>n;
    int c[26][26];
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        cin>>c[i][j];
    }
    // cout<<c[0][0]<<endl;
    map<pair<int,int>,int>mp;
    function<int(int,char)>f=[&](int i,char a)->int{

        if(i==n)
        return 0;
        if(mp.find({i,a})!=mp.end())
        return mp[{i,a}];
        int res=INT_MAX;
        for(int k=0;k<26;k++)
        {
            char cc=('a'+k);
            int cost=0;
            if(a!='*')
            cost=c[cc-'a'][a-'a'];

            //  cout<<cost<<endl;
            res=min(res,f(i+1,cc)+cost);
        }
        return mp[{i,a}]=res;
    };
     int x= f(0,'*');
     cout<<x<<endl;
}