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
        solve();
}
long long seg[12][(long long)(4e5)];
void update(long long id,long long s,long long e,long long l, long long r,long long val,long long level)
{
    // cout<<s<<" "<<e<<endl;
    if(l>e || s>r)
    return ;
    if(s>=l && e<=r)
    {
        // cout<<l<<" "<<r<<" "<<level<<endl;
        seg[level][id]=val;
        return ;
    }
    long long mid=(s+e)/2;
    update(2*id,s,mid,l,r,val,level);
    update(2*id+1,mid+1,e,l,r,val,level);
    seg[level][id]=seg[level][2*id]+seg[level][2*id+1];
}

long long get(long long id,long long s,long long e,long long l,long long r,long long level)
{
    if(l>e|| r<s)
    return 0;
    if(s>=l && e<=r)
    {
        return seg[level][id];
    }
    long long mid=(s+e)/2;
    return get(2*id,s,mid,l,r,level)+get(2*id+1,mid+1,e,l,r,level);
}
void solve()
{
    long long n,k;
    cin>>n>>k;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    vector<vector<long long>>dp(12,vector<long long>(n+1,0));

    dp[0][0]=1;
    update(1,0,n,0,0,1,0);
    for(long long i=0;i<n;i++)
     {
        for(long long k1=1;k1<=k+1;k1++)
        {
            long long x=get(1,0,n,0,a[i]-1,k1-1);
            // cout<<x<<" "<<a[i]<<" "<<k1<<endl;
            dp[k1][a[i]]=x;
            update(1,0,n,a[i],a[i],dp[k1][a[i]],k1);
        }
    }
    long long ans=get(1,0,n,0,n,k+1);
    cout<<ans<<endl;
}