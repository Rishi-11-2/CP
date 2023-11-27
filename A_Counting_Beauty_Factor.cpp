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
    string s;
    cin>>s;
    long long n=s.length();
    vector<long long>pos;
    for(long long i=0;i<n;i++)
    {
        if(s[i]=='o')
        pos.push_back(i);
    }
    long long v=0;
    if(s[0]=='v')
    v++;
    vector<long long>prefix;
    prefix.push_back(0);
    for(long long i=1;i<n;i++)
    {
        if(s[i]=='v')
        {
            v++;
            prefix.push_back(prefix.back());
        }
        else
        {
            long long count=0;
            if(v>0)
             count=(v-2+1);
            v=0;
            prefix.push_back(count+prefix.back());
        }
    }
    vector<long long>suffix(n,0LL);
    v=0;
    if(s[n-1]=='v')
    v++;
    for(long long i=n-2;i>=0;i--)
    {
        if(s[i]=='v')
        {
            v++;
            suffix[i]=suffix[i+1];
        }
        else
        {
            long long count=0;
            if(v>0)
            count=v-1;
            v=0;
            suffix[i]=count+suffix[i+1];
        }

    }
    // for(auto it:prefix)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // for(auto it:suffix)
    // {
    //     cout<<it<<" ";
    // }
    long long res=0;
    for(auto it:pos)
    {
        res=res+(prefix[it]*suffix[it]*1LL);
    }
    cout<<res<<endl;
}