#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.setf(ios::fixed);
    // cout.precision(10);
    // srand(time(NULL));
    
        solve();
}
int check(string &t,string &t1)
{
    int n=t.length();
    int m=t1.length();
    if (abs(m - n) > 1)
        return 0;
    int i=0;
    int j=0;
    int count=0;
    while(i<n && j<m)
    {
        if(count>1)
        return 0;
        if(t[i]!=t1[j])
        {
            count++;
            if(n>m)
            {
                i++;
            }
            else if(m>n)
            {
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        else
        {
            i++;
            j++;
        }
    }
    if(i<n || j<m)
    count++;
   if(count<=1)
   return 1;
   else
   return 0;
}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<string>v(n+1);
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        int x=check(v[i],s);
        if(x==1)
        res.push_back(i+1);
    }   
    cout<<res.size()<<endl;
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    cout<<endl;

}