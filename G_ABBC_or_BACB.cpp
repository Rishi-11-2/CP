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
    string s;
    cin>>s;
    int n=s.length();
    int flag=(s[0]=='B'||s[n-1]=='B');
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='B' && s[i+1]=='B')
        flag=1;
    }
    int curr=0;
    vector<int>len;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A')
        curr++;
        else
        {
            len.push_back(curr);
            curr=0;
        }
    }
    if(curr!=0)
    len.push_back(curr);
    int res=0;
    for(auto it:len)
    res+=it;
    if(!flag)
    res-=*min_element(all(len));
    cout<<res<<endl;    
}