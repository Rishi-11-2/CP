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
    int t;
        solve();
}
int seg[12][(int)(4e5)];
void update(int id,int s,int e,int l, int r,int val,int level)
{
    if(l>=e || s>=r)
    return ;

    if(s>=l && e<=r)
    {
        seg[level][id]=val;
    }
    int mid=(s+e)/2;
    update(2*id,s,mid,l,r,val,level);
    update(2*id+1,mid+1,e,l,r,val,level);
    seg[level][id]=seg[level][2*id]+seg[level][2*id+1];
}

int get(int id,int s,int e,int l,int r,int level)
{
    if(l>=e|| r<=s)
    return 0;
    if(s>=l && e<=r)
    {
        return seg[level][id];
    }
    int mid=(s+e)/2;
    return get(2*id,s,mid,l,r,level)+get(2*id+1,mid+1,e,l,r,level);
}
void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<vector<int>>dp(12,vector<int>(n+1,0));

    for(int i=0;i<n;i++)
    {
        dp[1][a[i]]=1;
    }
    for(int k1=2;k1<=k;k1++)
    {
        for(int i=0;i<n;i++)
        {
            update(1,0,n+1,a[i],a[i]+1,dp[k1-1][a[i]],k1-1);
            dp[k1][a[i]]=get(1,0,n+1,0,a[i]-1,k1-1);
        }
    }
    cout<<get(1,0,n,0,n+1,k+1)<<endl;
}