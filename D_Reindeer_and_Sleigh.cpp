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
        solve();
    
}
void solve()
{
    long long n,q;
    cin>>n>>q;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
   

    long long b[q];
    vector<pair<long long,long long>>v;
    for(long long i=0;i<q;i++)
    {
        cin>>b[i];
        v.push_back({b[i],i});



    }

    vector<long long>ans(q,0);
    sort(a,a+n);
    sort(all(v));

    long long i=0;
    long long j=0;
    long long s=0;
    while(i<n && j<q)
    {
        while(i<n && (s+a[i])<=v[j].first )
        {
            s+=a[i];
            i++;
        }
        ans[v[j].second]=(i);
        j++;
    }
    while(j<q)
    {
        ans[v[j].second]=(i);
        j++;
    }
    for(auto it:ans)
    cout<<it<<endl;
    


}