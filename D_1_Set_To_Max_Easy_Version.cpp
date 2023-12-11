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
    int a[n],b[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    cin>>b[i];
    
    vector<set<int>>prefix(n);
    vector<set<int>>suffix(n);
    // vector<int>suffix(n,0);
    prefix[0].insert(a[0]);
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1];
        // prefix[i].insert(a[i]);
        // if(a[i]==b[i])
        // {
            if(a[i]<*prefix[i].rbegin())
            prefix[i].clear();
        // }
            prefix[i].insert(a[i]);
    }
    suffix[n-1].insert(a[n-1]);
    for(int i=n-2;i>=0;i--)
    {   
        suffix[i]=suffix[i+1];
        // suffix[i].insert(a[i]);
     
            if(b[i]<*suffix[i].rbegin())
            suffix[i].clear();
        // }
            suffix[i].insert(a[i]);
        
    }
    // for(auto it:prefix)
    // cout<<it<<" ";
    // cout<<endl;
    // for(auto it:suffix)
    // cout<<it<<" ";
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i])
        continue;
       
       if(i>0 &&(prefix[i-1].find(b[i])!=prefix[i-1].end())||i<n-1 && (suffix[i+1].find(b[i])!=suffix[i+1].end()))
       continue;
       flag=0;
    }
    if(flag)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}