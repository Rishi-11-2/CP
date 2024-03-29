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
        solve();
}
void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=1;i<=n;i++)
    {
        int t,x;
        cin>>t>>x;
        v.push_back({t,x});
    }
    multiset<int>s;
    int count=0;
    int res=0;
    vector<int>ans;
    for(int i=n-1;i>=0;i--)
    {
        if(v[i].first==2)
        {
            s.insert(v[i].second);
            count++;
        }
        else
        {
            if(s.find(v[i].second)!=s.end())
            {
                ans.push_back(1);
                s.erase(s.find(v[i].second));
                count--;
            }
            else
            ans.push_back(0);
        }
        // debug(count);
        res=max(res,count);

    }
    if(count!=0)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<res<<endl;
    reverse(all(ans));
    for(auto it:ans)
    cout<<it<<" ";
    cout<<endl;
}
