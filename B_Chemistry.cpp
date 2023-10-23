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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>f(26,0);
    for(int i=0;i<n;i++)
    {
        f[s[i]-'a']++;
    }
    int flag=0;
    for(int i=0;i<26;i++)
    {
        if(f[i]%2)
        flag=1;
        if(f[i]%2 && k>0)
        {
            f[i]--;
            k--;
        }
    }
    int count=0;
    for(int i=0;i<26;i++)
    {
        if(f[i]%2)
        count++;
    }
    if(flag==0)
    {
        cout<<"YES"<<endl;
        return;
    }
    else if(count>1)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}