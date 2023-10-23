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
    string s;
    cin>>s;
    int n=s.length();
    string x="1234567890";
    map<int,int>pos;
    for(int i=0;i<x.length();i++)
    {
        int y=x[i]-'0';
        pos[y]=i;
    }
    int curr=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int y=s[i]-'0';
        res+=(abs(curr-pos[y]))+1;
        // cout<<pos[y]<<endl;
        curr=pos[y];
    }
    cout<<res<<endl;

}