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
void solve()
{
    long long n,m;
    cin>>n>>m;
    vector<long long>a(n);
    for(long long i=0;i<n;i++)
    cin>>a[i];
    
    vector<long long>va;
    vector<long long>fva;
    for(long long i=0;i<n;i++)
    {
        long long count=1;
        while(a[i]%m==0)
        {
            a[i]=a[i]/m;
            count=count*m;
        }
        va.emplace_back(a[i]);
        fva.emplace_back(count);

    }
    long long n1;
    cin>>n1;
    vector<long long>b(n1);
    vector<long long>vb;
    vector<long long>fvb;
    for(long long i=0;i<n1;i++)
    {
        cin>>b[i];
        long long count=1;
        while(b[i]%m==0)
        {
            b[i]=b[i]/m;
            count=count*m;
        }
        vb.emplace_back(b[i]);
        fvb.emplace_back(count);
    }
    long long i=0;
    long long j=0;
    long long delcount=0;
    while(i<n && j<n1)
    {
        long long i1=i;
        while(i1<n && va[i1]==va[i])
        {
            delcount+=fva[i1];
            i1++;
        }
        long long i2=j;
        while(i2<n1 && vb[i2]==va[i])
        {
            delcount-=fvb[i2];
            i2++;
        }
        if(delcount)
        {
            cout<<"No"<<endl;
            return;
        }
        i=i1;
        j=i2;
        // debug(i,j);
    }
    if(i<n ||j<n1)
    {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
}