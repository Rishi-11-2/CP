#include <bits/stdc++.h>
using namespace std;
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

long long f(long long i,long long tight,long long zero,string &s,vector<vector<vector<long long>>>&dp,long long n)
{

    if(i==n)
        {
            if(n-zero<=3)
            return 1;
            return 0;
        }
        if(dp[i][zero][tight]!=-1)
        return dp[i][zero][tight];
        long long low=0;
        long long high=(tight==1)?(s[i]-'0'):9;
        long long res=0;
        for(long long j=low;j<=high;j++)
        {
            // nums[i]=(j+'0');
            long long newTight=0;
            if(tight==1)
            {
                if(j==high)
                newTight=1;
            }
            long long newZero=zero;
            if(j==0)
            newZero++;
           res=res+f(i+1,newTight,newZero,s,dp,n);
        }

        return dp[i][zero][tight]=res;
}
void solve()
{
    long long l,r;
    cin>>l>>r;
    string ls=to_string(l);
    string rs=to_string(r);
    long long n=rs.length();
    while(ls.length()<n)
    {
        char c='0';
        ls=c+ls;
    } 
    vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(n+1,vector<long long>(2,-1)));
    long long a=f(0,1,0,ls,dp,n);
    dp.assign(n+1,vector<vector<long long>>(n+1,vector<long long>(2,-1)));
    long long b=f(0,1,0,rs,dp,n);
    long long count=(b-a);
    long long cc=0;
    for(long long i=0;i<n;i++)
    {
        if(ls[i]!='0')
        cc++;
    }
    if(cc<=3)
    count++;
    cout<<count<<endl;
}