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
    vector<int>one(n,0);
    reverse(all(s));
    one[0]=(s[0]=='1')?1:0;
    for(int i=1;i<n;i++)
    {
        one[i]=one[i-1];
        if(s[i]=='1')
        one[i]++;
    }
    vector<int>res;
    int count=0;
    vector<int>pos;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            count++;
            pos.push_back(i);
        }
    }
    sort(all(pos));
    reverse(all(pos));
    int m=pos.size();
    int y=n-count;
    int xx=0;
    int ans=0;
    
    // for(int i=0;i<n;i++)
    // {
    //     cout<<one[i]<<" ";
    // }
    // cout<<endl;
    
    // cout<<ans<<endl;
    // reverse(all(s));
    for(int i=n;i>=1;i--)
    {
        if(i>((n)-count))
        {
            res.push_back(-1);
            continue;
        }
        else
        {
            int ans=0;
            xx=0;
            for(int k=(i+count)-1;k>=i;k--)
            {
                // cout<<i<<" "<<pos[xx]<<endl;
                ans+=(i-pos[xx]);
                xx++;
            }
            res.push_back(ans);
        }
    }
    reverse(all(res));
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}