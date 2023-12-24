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
    long long a,m,l,r;
    cin>>a>>m>>l>>r;
    long long dist1=(abs(r-a))/m;
    long long dist2=(abs(l-a))/m;
    long long z=0;
    if(a>=l && a<=r)
    {
        z=dist1+dist2+1LL;
        // debug(dist1,dist2);
    }
    else
    {
        z=abs(dist1-dist2);
        if(a<l && abs(l-a)%m==0 )
        z++;

        if(a>r && abs(r-a)%m==0 )
        z++;
    }
    
    // debug(dist1%m,dist2%m);
    
    cout<<z<<endl;
}