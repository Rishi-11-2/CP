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
long long stt(string s)
{
     stringstream geek;
 
    geek << s;
    long long x = 0;
    geek >> x;
    return x;
}
void solve()
{
    int n;
    cin>>n;
    string s="1";
    vector<string>v;
    v.push_back(s);
    for(int i=2;i<=111;i++)
    {
        s=s+'1';
        v.push_back(s);
    }
    set<long long>ss;
    for(int i=0;i<13;i++)
    {
        for(int j=0;j<13;j++)
        {
            for(int k=0;k<13;k++)
            {
                long long x=stt(v[i]);
                long long y=stt(v[j]);
                long long z=stt(v[k]);
                // debug(x+y+z);
                long long res=x+y+z;
                // debug(res);
                ss.insert(res);
            }
        }
    }
    // for(auto it:ss)
    // cout<<it<<endl;
    // cout<<(int)ss.size()<<endl;
    vector<long long>vv(all(ss));
    cout<<vv[n-1]<<endl;

}