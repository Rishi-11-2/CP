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
    string s;
    cin>>s;
    vector<set<int>>attackedBy(n+1);
    vector<set<int>>attackedTo(n+1);
    for(int i=1;i<=n;i++)
    {
        int right=(i+1)%(n+1);
        int left=(i-1);
        if(left<1)
        left+=n;
        if(s[i-1]=='R')
        {
            attackedTo[i].insert(right);
            attackedBy[right].insert(i);
        }
        else if(s[i-1]=='L')
        {
            attackedTo[i].insert(left);
            attackedBy[left].insert(i);
        }
    }
    map<pair<int,vector<int>>,int>mp;
    function<int(int,vector<set<int>>,vector<set<int>>)>f=[&](int i,vector<set<int>>attackedBy,vector<set<int>>attackedTo)->int{
        if(i==n)
        {
             for(int i=1;i<=n;i++)
            {
                if(attackedBy[i].size()==1)
                {
                    if(attackedBy[i]!=attackedTo[i])
                    {
                        // cout<<i<<endl;
                        return 0x3f3f3f3f;
                    }
                }
            }
            return 0;
        }
        int res=f(i+1,attackedBy,attackedTo);
        if(attackedBy[i].size()==1)
        {
            if(attackedBy[i]!=attackedTo[i])
            {
                // cout<<i<<endl;
                int x=*attackedBy[i].begin();
                int y=*attackedTo[i].begin();
                attackedBy[y].erase(i);
                attackedTo[i].erase(y);
                attackedTo[i].insert(x);
                res=min(res,1+f(i+1,attackedBy,attackedTo));
            }
        }
        return  res;
    };
    int count=f(0,attackedBy,attackedTo);
    cout<<count<<endl;
}