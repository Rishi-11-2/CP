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
    
        solve();
    
}
void solve()
{
    long long n;
    cin>>n;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    long long x=(pow(10LL,n));
    long long count=0;
    for(long long i=0;i*i<=x;i++)
    {
        string t=to_string(i*i);
        t.resize(n,'0');
        sort(t.begin(),t.end());
        if(t==s)
        {
            count++;
        }
    }   
    cout<<count<<endl;
}