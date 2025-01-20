#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,long long ,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong long s)
typedef tree < pair<long long ,long long >, null_type,less<pair<long long ,long long >>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long  t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
long long  dp[20][3][3][10];

long long  f(long long  i,long long  tight,long long  start,long long  dm,string &s,long long  n)
{
        if(i==n)
        {
            // debug(n,s);
            if(start==0)
            return 0;
            return 1;
        }

        if(dp[i][tight][start][dm]!=-1)
        return dp[i][tight][start][dm];
        // debug(n,s);
        long long  res=0;
        // if(start==0)
        // res+=f(i+1,tight,start,dm);
        
        long long  upper_bound=(tight==1)?(s[i]-'0'):9;

        long long  lower_bound=0;

        for(long long  j=lower_bound;j<=upper_bound;j++)
        {
            long long  new_tight=0;
            if(tight==1 && j==upper_bound)
            new_tight=1;
            
            long long  new_dm=dm;
            if(start==0)
            new_dm=j;
            
            if(dm!=-1 && start==1 && j>=dm)
            continue;

            long long  new_start=1;

            if(j==0 && start==0)
            {
                new_start=0;
                new_dm=-1;
            }
            
            res+=f(i+1,new_tight,new_start,new_dm,s,n);
        }

        return dp[i][tight][start][dm]= res;
}
void solve()
{
    long long  n=0;
    string s="";

    

    long long  l,r;
    cin>>l>>r;

    string sl=to_string(l-1);

    string sr=to_string(r);

    char c='0';
    while(sl.length()<sr.length())
    {
        sl=c+sl;
    }
    n=sl.length();

    s=sl;

    // debug(n,s);

    // debug(sl,sr);
    memset(dp,-1,sizeof(dp));
    long long  left=f(0,1,0,-1,sl,n);

    n=sr.length();

    s=sr;
    memset(dp,-1,sizeof(dp));

    long long  right=f(0,1,0,-1,sr,n);

    // debug(left,right);
    cout<<(right-left)<<endl;



}