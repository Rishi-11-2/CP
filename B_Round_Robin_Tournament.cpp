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
bool compare(pair<int,int>&a,pair<int,int>&b)
{
    if(a.first==b.first)
    return a.second<b.second;
   return a.first>b.first;
}
void solve()
{
    int n;
    cin>>n;
    vector<string>s(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    vector<pair<int,int>>v;
    for(int i=1;i<=n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(s[i][j]=='o')
            {
                count++;
            }
        }
        // cout<<i<<" "<<count<<endl;
        v.push_back({count,i});
    }
    sort(v.begin(),v.end(),compare);
    for(auto it:v)
    {
        cout<<it.second<<" ";
    }
    cout<<endl;
}