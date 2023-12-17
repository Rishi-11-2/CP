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
    long long n;
    cin>>n;
    vector<pair<long long,long long>>v;
    map<long long,vector<long long>>first;
    map<long long,vector<long long>>second;
    set<long long>s;
    for(long long i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
        s.insert(y);
        if(x==1)
        {
            first[y].push_back(i-1);
        }
        if(x==2)
        {
            second[y].push_back(i-1);
        }
    }
    map<long long,long long>mp;
    for(auto it:s)
    {
        auto v1=first[it];
        auto v2=second[it];
        long long i=0;
        long long j=0;
        long long n1=v1.size();
        long long n2=v2.size();
        if(n2>n1)
        {
            cout<<-1<<endl;
            return;
        }
        while(j<n2)
        {
            long long idx=-1;
            while(i<n1 && v1[i]>v2[j])
            {
                i++;
            }
            while(i<n1 && v1[i]<v2[j])
            {
                idx=i;
                i++;
            }
            if(idx==-1)
            {
                cout<<-1<<endl;
                return;
            }
            mp[v1[idx]]=1;
            // debug(it,j,idx);
            j++;
        }
    }
    // long long res=(long long)(mp.size());
    long long res=0;
    long long x=0;
    vector<long long>ans;
    for(long long i=0;i<n;i++)
    {
        if(v[i].first==1)
        {
            if(mp[i]==1)
            {
                x++;
                ans.push_back(1);
            }
            else
            ans.push_back(0);
        }
        else
        {
            x--;
        }
        res=max(res,x);
    }
    cout<<res<<endl;
    for(auto it:ans)
    cout<<it<<" ";
    cout<<endl;
}