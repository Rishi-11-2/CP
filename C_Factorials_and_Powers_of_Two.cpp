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
    vector<long long>v;
    long long fact[15];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t;
    fact[0]=1;
    for(long long i=1;i<=14;i++)
    {
        fact[i]=(1LL*i)*(fact[i-1]*1LL);
    }
    long long pow=1LL;
    while(pow<=(long long)(1e13))
    {
        v.push_back(pow);
        pow=(2LL*pow);
    }
    cin >> t;
    while (t--)
    {
        solve();
    }
}
long long count(long long n)
{
    long long m=(long long)(v.size());
    long long c=0;
    for(long long i=m-1;i>=0;i--)
    {
        if(v[i]<=n)
        {
            c++;
            n-=v[i];
        }

    }
    return c;
}
void solve()
{
    long long n;
    cin>>n;

    function<long long(long long,long long)>f=[&](long long n,long long i)->long long{
        if(n<0)
        return (long long)(1e13);        
        if(i==15)
        {
            return count(n);
        }

        long long res=min(1+f(n-fact[i],i+1),f(n,i+1));

        return res;
    };

    long long x=f(n,0);
    cout<<x<<endl;
}