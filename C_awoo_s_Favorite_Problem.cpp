#include <bits/stdc++.h>
using namespace std;
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
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
    vector<int>s1a;
    vector<int>s2a;
    vector<int>s1c;
    vector<int>s2c;
    string s1b,s2b;
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<"YES"<<endl;
        return;
    }
    if(n==1)
    {
        if(a==b)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]=='a')
        s1a.push_back(i);
        if(a[i]=='c')
        s1c.push_back(i);
        if(a[i]!='b')
        s1b+=a[i];
        if(b[i]=='a')
        s2a.push_back(i);
        if(b[i]=='c')
        s2c.push_back(i);
        if(b[i]!='b')
        s2b+=b[i];
    }
    // debug(s1b,s2b);
    if((int)(s1a.size())!=(int)(s2a.size())|| (int)(s1c.size())!=(int)(s2c.size())||s1b!=s2b )
    {
        cout<<"NO"<<endl;
        return;
    }

    int flag=0;

    for(int i=0;i<s1a.size();i++)
    {
        if(s1a[i]>s2a[i])
        flag=1;
    }
    for(int i=0;i<s1c.size();i++)
    {
        if(s2c[i]>s1c[i])
        flag=1;
    }
    if(flag)
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
}