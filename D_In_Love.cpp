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
    long long q;
    cin>>q;
    multiset<pair<long long,long long>>s;
    set<pair<int,int>>st;
    vector<string>res;
    for(long long i=1;i<=q;i++)
    {
        char c;
        cin>>c;
        if(c=='+')
        {
            long long l,r;
            cin>>l>>r;
            s.insert({l,r});
            st.insert({l,r});
        }
        if(c=='-')
        {
            long long l,r;
            cin>>l>>r;
            s.erase(s.find({l,r}));
            if(s.find({l,r})==s.end())
            {
                st.erase({l,r});
            }
        }
        // cout<<st.size()<<endl;
        if(s.empty())
        {
            res.push_back("NO");
            continue;
        }
        else
        {
            auto x=*s.begin();
            auto y=*(s.rbegin());
            if(y.first>x.second)
            {
                res.push_back("YES");
            }
            else
            {
                res.push_back("NO");
            }
        }
    }
    // cout<<"hi"<<endl;
    for(auto it:res)
    {
        cout<<it<<endl;
    }
}