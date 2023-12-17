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
        solve();
}
void solve()
{
    string s;
    string t;
    cin>>s;
    cin>>t;

    map<string,int>mp;
    mp["AB"]=1;
    mp["BC"]=1;
    mp["CD"]=1;
    mp["DE"]=1;
    mp["EA"]=1;
    mp["AC"]=2;
    mp["AD"]=2;
    mp["BD"]=2;
    mp["CE"]=2;
    mp["BE"]=2;
    for(auto it:mp)
    {
        string x=it.first;
        reverse(all(x));
        mp[x]=it.second;
    }

    int a=mp[s];
    int b=mp[t];
    if(a==b)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
}
