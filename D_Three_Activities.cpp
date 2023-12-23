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
bool cmp(const pair<long long,long long> &a,
              const pair<long long,long long> &b)
{
    if(a.first==b.first)
    return (a.second < b.second);

   return (a.first>b.first);
}
 
void solve()
{
    long long n;
    cin>>n;
    vector<pair<long long,long long>>a(n);
    vector<pair<long long,long long>>b(n);
    vector<pair<long long,long long>>c(n);
    for(long long i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        a.push_back({x,i});
    }
    
    for(long long i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        b.push_back({x,i});
    }
    
    for(long long i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        c.push_back({x,i});
    }
    sort(all(a),cmp);
    sort(all(b),cmp);
    sort(all(c),cmp);
    long long res=0;
    for(long long i=0;i<3;i++)
    {
        for(long long j=0;j<3;j++)
        {
            for(long long k=0;k<3;k++)
            {
                if(a[i].second==b[j].second||b[j].second==c[k].second||c[k].second==a[i].second)
                continue;                
                res=max(res,a[i].first+b[j].first+c[k].first);
            }
        }
    }
    cout<<res<<endl;

}