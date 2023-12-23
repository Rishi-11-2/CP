#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
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
   /*dp solution
    from (i,j)===(position,step) we can go to either (i-1,j-1) or (i-1,j)(this is because we at any step we can make a move which will be the multiple of (k+step-1))*/

    /* now suppose from k=1 after 3 steps we will have to be atleast in this position : (1+2+3)=6 i.e. (n*(n+1))/2*/
    /* for k=2 it will only increase*/

    int n,k;
    cin>>n>>k;
    const int mod=(int)(998244353);
    vector<int>prev(n+1,0);
    vector<int>ans(n+1,0);
    prev[0]=1;
    for(int j=1;j<=650;j++)
    {
        vector<int>curr(n+1,0);
        for(int i=1;i<=n;i++)
        {
            /* dp[i][j]=dp[i-move][j-1]+dp[i-move][j] */

            int move=(j+k-1);
            if(i-move>=0)
            {
                curr[i]=(prev[i-move]%mod+curr[i-move]%mod)%mod;
            }
            ans[i]=(ans[i]%mod+curr[i]%mod)%mod;
        }
        prev=curr;
    }

    for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
    cout<<endl;

}