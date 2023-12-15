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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>pos;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        pos.push_back(i);
    }
    int m=pos.size();
    if(m!=0)
    {
         int i=0;
        int j=m-1;
        int diff1=abs(pos[i]-0);
        int diff2=abs(pos[j]-(n-1));
        if(m==1)
        {
            if(diff2<=k)
            {
                swap(s[n-1],s[pos[0]]);
            }
            else if(diff1<=k)
            {
                swap(s[0],s[pos[0]]);
            }
        }
        else if(m>1)
        {
            // debug(diff1,diff2);
            // int minm=min(diff1,diff2);
            if(diff2<=k)
            {
            swap(s[n-1],s[pos[j]]);
            k-=diff2;
            }
            if(diff1<=k)
            {
                swap(s[0],s[pos[i]]);
            }
        }
    }
    int res=0;
    for(int i=0;i<n-1;i++)
    {
        string x="";
        for(int j=i;j<i+2;j++)
        {
            x+=s[j];
        }
        res+=stoi(x);
    }
    cout<<res<<endl;
}