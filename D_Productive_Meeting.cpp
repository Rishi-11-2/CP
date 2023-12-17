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
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;
    priority_queue<pair<long long,long long>>pq;
    long long arr[n];
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>0)
        pq.push({arr[i],i});
    }
    map<pair<long long,long long>,long long>mp;
    long long count=0;
    while((long long)(pq.size())>1)
    {
        auto it1=pq.top();
        pq.pop();
        auto it2=pq.top();
        pq.pop();
        long long x=it1.first;
        long long idx=it1.second;
        long long y=it2.first;
        long long idy=it2.second;
        long long c=min(x,y);
        // debug(x,y,c);
        x=x-c;
        y=y-c;
        count+=c;
        mp[{idx,idy}]+=c;
        if(x>0)
        {
            pq.push({x,idx});
        }
        if(y>0)
        {
            pq.push({y,idy});
        }
    }
    cout<<count<<endl;
    for(auto it:mp)
    {
        for(long long i=1;i<=it.second;i++)
        {
            cout<<it.first.first+1<<" "<<it.first.second+1<<endl;
        }
    }
}