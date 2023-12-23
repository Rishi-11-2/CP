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
    long long n;
    cin>>n;
    vector<vector<long long>>v(2,vector<long long>(26,0));
    v[0][0]++;
    v[1][0]++;
    long long fl=1;
    long long sl=1;
    function<long long(void)>check=[&](void)->long long{

        long long flag=0;
        for(long long i=25;i>=1;i--)
        {
            if(v[1][i]>0)
            return 1;

            if(v[0][i]>0)
            flag=1;
        }
        if(flag)
        return 0;
        if(v[1][0]>v[0][0])
        return 1;
         
         return 0;
    };
        vector<string>ans;
    for(long long i=1;i<=n;i++)
    {
        long long d,k;
        string x;
        cin>>d>>k;
        cin>>x;
        for(char c:x)
        {
            v[d-1][c-'a']+=k;
        }
        if(check())
        ans.push_back("YES");
        else
        ans.push_back("NO");
    }
    for(auto it:ans)
    cout<<it<<endl;
}