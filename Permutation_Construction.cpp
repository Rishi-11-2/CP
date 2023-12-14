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
    long long n,x;
    cin>>n>>x;
    // debug(n,x);
    if(n%2)
    {
        if(x==((n/2)+1))
        {
        cout<<-1<<endl;
        return;     
        }
        // int y=x-1;
        //     vector<int>v;
        //     for(int i=1;i<=n;i++)
        //     v.push_back(i);

        //     swap(v[0],v[y]);
        //     swap(v[n-1],v[n-1-y]);
        //     for(auto it:v)
        //     cout<<it<<" ";
        //     cout<<endl;
        //     // return
    }
    if(x==1)
    {
        for(long long i=1;i<=n;i++)
        cout<<i<<" ";
        cout<<endl;
        return;
    }
    if(x==n)
    {
        for(long long i=n;i>=1;i--)
        cout<<i<<" ";
        cout<<endl;
        return;
    }
    vector<long long>v;
    for(long long i=1;i<=n;i++)
    v.push_back(i); 
    
    long long y=n-x;
    swap(v[0],v[x-1]);
    swap(v[n-1],v[y]);

    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;
}