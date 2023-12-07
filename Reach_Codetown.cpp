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
    int n=8;

    string vowels="AEIOU";
    set<char>vs;
    for(char c:vowels)
    {
        vs.insert(c);
    }
    string target="CODETOWN";
    for(int i=0;i<8;i++)
    {
        // cout<<s[i]<<" "<<target[i]<<endl;
        if(vs.find(s[i])!=vs.end() && vs.find(target[i])!=vs.end())
        continue;
        if(vs.find(s[i])==vs.end() && vs.find(target[i])==vs.end())
        continue;
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}