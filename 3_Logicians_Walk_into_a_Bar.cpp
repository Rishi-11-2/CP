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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int flag=1;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            flag=0;
            cout<<"NO"<<endl;
        }
        else if(flag==0)
        {
            cout<<"NO"<<endl;
        }
        else if(s[i]=='1')
        {
            count++;
            if(count<n)
            cout<<"IDK"<<endl;
        }
    }
    if(count==n)
    cout<<"YES"<<endl;
}