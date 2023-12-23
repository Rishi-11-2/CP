#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
bool cmp(pair<long long,long long>&a,pair<long long,long long>&b)
{
    if(a.first==b.first)
    return a.second<b.second;
    

    return a.first>b.first;
}
void solve()
{
    long long n;
    cin>>n;
    long long a[n];
    long long b[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    
    for(long long i=0;i<n;i++)
    cin>>b[i];
    
    vector<pair<long long,long long>>v;

    for(long long i=0;i<n;i++)
    {
        v.push_back({a[i]+b[i],i});
    }

    sort(all(v),cmp);
    // for(auto it:v)
    // {
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    long long p=0;
    long long alice=0;
    long long bob=0;
    for(long long i=0;i<n;i++)
    {
        if(p==0)
        {
            alice+=a[v[i].second]-1;
            p=1-p;
        }
        else
        {
            bob+=b[v[i].second]-1;
            p=1-p;
        }
    }
    cout<<alice-bob<<endl;
}