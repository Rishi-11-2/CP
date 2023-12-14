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
    long long arr[n];
    multiset<long long>s;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        s.insert(arr[i]);
    }
    vector<long long>b(n,0);
    long long count=0;
    long long sum=0;
    for(long long i=0;i<n;i++)
    {
        auto vv=*s.begin();
        // debug(vv,sum);
        auto it=s.lower_bound(sum+1);
        if(sum>=vv && it!=s.end())
        {
                b[i]=*it;
               s.erase(it);
               sum+=b[i];
        }
        else
        {
            // cout<<*s.begin()<<endl;
            b[i]=*s.begin();
            s.erase(s.begin());
            sum+=b[i];
        }
        // cout<<sum<<endl;
        // debug(sum)
    }
     sum=0;
    for(long long i=0;i<n;i++)
    {
        if(sum>=b[i])
        count++;
        sum+=b[i];
    }
    cout<<count<<endl;
    for(long long i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
}