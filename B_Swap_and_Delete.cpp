#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
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
    int one=0;
    int zero=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        zero++;
        if(s[i]=='1')
        one++;
    }
    if(zero==one)
    {
        cout<<0<<endl;
        return;
    }
    string z;
    char c='0';
    for(int i=0;i<n;i++)
    {
        z+=c;
    }
    // for(int i=0)
    // debug(z);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
           if(one>0)
           {
            one--;
            z[i]='1';
           }
           else
           {
             z[i]='0';
             zero--;
           }
        }
        if(s[i]=='1')
        {
            if(zero>0)
            {
                zero--;
                z[i]='0';
            }
            else
            {
                z[i]='1';
                one--;
            }
        }
    }
    // debug(z);
    int i=0;
    int j=0;
    int count=0;
    while(i<n && j<n)
    {
        if(s[i]!=z[j])
        {
            i++;
            j++;
        }
        else
        {
            count++;
            j++;
        }
    }

    cout<<count<<endl;

}