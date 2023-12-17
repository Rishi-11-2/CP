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
    stack<pair<char,int>>st;
    for(int i=0;i<n;i++)
    {
        if(st.empty())
        st.push({s[i],i});
        else
        {
            while(!st.empty() && s[i]>=st.top().first)
            {
                st.pop();
            }
            st.push({s[i],i});
        }

    }
    vector<pair<char,int>>v;
    set<int>stt;
    while(!st.empty())
    {
        v.push_back(st.top());
        stt.insert(st.top().second);
        // debug(st.top().second);
        st.pop();
    }
    for(auto it:stt)
    debug(it);
    // for(auto it:v)
    // cout<<it.first<<" "<<it.second<<endl;
    int j=0;
    char prev='/';
    int count=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(stt.find(i)!=stt.end())
        {
            if(prev!='/')
            {
                if(prev>v[j].first)
                {
                    cout<<-1<<endl;
                    return;
                }
            }
            debug(i,j);
            count++;
            prev=v[j].first;
            j++;
        }
        else
        {
            if(prev>s[i])
            {
                cout<<-1<<endl;
                return ;
            }
            
            prev=s[i];
        }
    }
    cout<<count-1<<endl;

}