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
    // cin >> t;
        solve();
}
void solve()
{
    long long n;
    cin>>n;
    vector<long long>bitmasks(32,0);
    vector<string>ans;
    long long sum=0;
    function<void(void)>rf=[&](void)->void{
        for(long long i=0;i<=29;i++)
        {
            if((sum&(1<<i))!=0)
            {
                bitmasks[i]=1;
            }
        }
    };
    function<long long(long long)>f=[&](long long v)->long long{
        for(long long i=29;i>=0;i--)
        {
            if(bitmasks[i]!=0)
            {
               long long count=1;
               long long k=(1<<i);
               while(k*count<=v && count<=bitmasks[i])
               {
                 count++;
               }
               if(k*count>v)
               count--;
               while(count>bitmasks[i])
               count--;
                // debug(k,count,v);
               v-=(k*count);
            }
        }
        return (v==0);
    };
    for(long long i=1;i<=n;i++)
    {
        long long t,v;
        cin>>t>>v;
        if(t==1)
        {
            bitmasks[v]++;
        }
        else
        {
            rf();
            // sum=0;
            long long check=f(v);
            if(check)
            ans.push_back("YES");
            else
            ans.push_back("NO");
        }
    }
    for(auto it:ans)
    cout<<it<<endl;
}