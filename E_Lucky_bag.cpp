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
    cout.precision(18);
    srand(time(NULL));
        solve();
}
void solve()
{
    long long n,d;
    cin>>n>>d;
    long long wt[n];
    long double avg=0;
    for(long long i=0;i<n;i++)
    {
        cin>>wt[i];
        avg+=wt[i]*1.0;
    }
    avg=(avg/(d*1.0));
    vector<long long>sum((1<<n)+1,0);
    for(long long i=0;i<=(1<<n);i++)
    {
        for(long long j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                sum[i]+=wt[j];
            }
        }
        // cout<<sum[i]<<endl;
    }
    // cout<<avg<<endl;
    vector<vector<long double>>dp(d+1,vector<long double>((1<<n)+1,-1.0));
    function<long double(long long,long long)>f=[&](long long i,long long mask)->long double{

        if(i==d)
        {
            if(mask!=0)
            return 1e18*1.0;
            // cout<<mask<<endl;
            return 0.0;
        }
        if(dp[i][mask]+1.0>0.0)
        return dp[i][mask];
        long double res=f(i+1,mask)+avg*avg;
        long long submask=mask;
        while(submask>0)
        {
            // cout<<submask<<endl;
            res=min(res,(sum[submask]*1.0-avg)*(sum[submask]*1.0-avg)*1.0+f(i+1,mask^submask));
            submask=(submask-1)&mask;
        }
        return dp[i][mask]= res;
    };
    long long mask=(1<<n)-1;
    long double res=f(0,mask)/(d*1.0);
    cout<<res<<endl;
}