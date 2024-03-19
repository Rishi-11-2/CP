#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
void solve();
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
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
    // debug(n);
    char s[n];
    cin>>s;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int x=(int)(s[i]-'0');
        sum+=x;
    }
    string res="";
    int carry=0;
    int xx=sum;
    int i=n-1;
    while(i>=0)
    {
        // debug(sum,carry);
        sum=xx+carry;
        // debug(sum,carry);
         carry=sum/10;
        int a=sum%10;
        char c=(a+'0');
        res+=c;
        int x=(int)(s[i]-'0');
        xx-=x;
        i--;
    }
    char c=(carry+'0');
    res+=c;
    while(res.back()=='0')
    {
        res.pop_back();
    }
    reverse(all(res));
    cout<<res<<'\n';
    
}