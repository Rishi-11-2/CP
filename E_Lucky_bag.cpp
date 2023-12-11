#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(17);
    srand(time(NULL));
        solve();
}
double dp[16][(1<<16)+1];
double f(long long i,long long mask,vector<double>v,vector<double>&w,int n,int d,double avg)
{
    if(i==n)
        {
            // cout<<mask<<endl;
            double res=0.0;
            for(long long j=0;j<d;j++)
            {
                // cout<<v[j]<<" ";
                res+=((v[j]-avg)*(v[j]-avg)*1.0);
            }
            // cout<<endl;
            // cout<<res<<endl;
            res=res/(d*1.0);
            return res;
        }
        if(dp[i][mask]!=-1)
        return dp[i][mask];
        double res=0;

        double ans=1e15;

        // ans=min(ans,f(i+1,mask,v,w,n,d,avg));
        long long newMask=mask;
            // ans=min(ans,f(i+1,newMask,v,w,n,d,avg));
        for(long long j=0;j<d;j++)
        {

            v[j]+=w[i];
            newMask=mask|(1<<j);
            ans=min(ans,f(i+1,newMask,v,w,n,d,avg));
            v[j]-=w[i];
        }
        return dp[i][mask]= ans;
}
void solve()
{
    long long n,d;
    cin>>n>>d;
    vector<double>w(n);
    double s=0;
    for(long long i=0;i<n;i++)
    {
        cin>>w[i];
        s+=w[i]*1.0;
    }
    for(long long i=0;i<=(15*1LL);i++)
    {
        for(long long j=0;j<=((1<<16)*1LL);j++)
        dp[i][j]=-1;
    }
    double avg=((s*1.0)/(d*1.0));
    // cout<<avg<<endl;
    vector<double>bags(d,0);

    /* i- bag index mask- will be used to identify whether the item has chosen yet or not*/
    double x=f(0,0,bags,w,n,d,avg)*1.0;
    cout<<x<<endl;

}