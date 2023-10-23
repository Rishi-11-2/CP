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
    string s,t;
    cin>>s>>t;
    vector<set<int>>prev(26);
    int n=s.length();
    set<char>st;
    for(int i=0;i<n;i++)
    {
        st.insert(s[i]);
        prev[s[i]-'a'].insert(i);
    }
    int m=t.length();
    for(int i=0;i<m;i++)
    {
        if(st.find(t[i])==st.end())
        {
            cout<<-1<<endl;
            return;
        }
    }
    int count=0;
    int i=m-1;
    while(i>=0)
    {
        int pos=*(prev[t[i]-'a'].rbegin());
        int j=i-1;
        while(pos>-1 && j>=0)
        {
            cout<<pos<<" "<<j<<" ";
            auto jj=prev[t[j]-'a'];
            if((pos-1)<(*jj.begin()))
            break;
            auto iik=jj.lower_bound(pos-1);
            pos=*(iik);
            j--;
        }
        cout<<endl;
        i=j;
        count++;
    }
    cout<<count<<endl;
}