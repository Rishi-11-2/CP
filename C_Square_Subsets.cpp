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
bool is_prime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}
void solve()
{
    int n;
    cin>>n;
    int a[n];
    map<int,int>mp2;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp2[a[i]]++;
    }
    vector<int>v;
    vector<int>maskk(71,0);
    const int mod=(int)(1e9)+7;
    vector<int>ways(100005,0);
    ways[0]=1;
    for(int i=1;i<=(int)(1e5);i++)
    {
        ways[i]=(ways[i-1]%mod*2%mod)%mod;
    }
    // cout<<ways[4]<<endl;
    for(int i=2;i<=70;i++)
    {
        if(is_prime(i))
        v.push_back(i);

    //    mp2[i]++;
    }
    int m=(int)v.size();
    // cout<<m<<endl;
    for(int i=2;i<=70;i++)
    {
        int yy=i;
        map<int,int>mp;
        int idx=0;
        while(yy>1)
        {
            if(yy%v[idx]==0)
            {
                yy/=v[idx];
                mp[v[idx]]++;
            }
            else
            idx++;
        }
        int newMask=0;

        for(int i=0;i<20;i++)
        {
            if(mp[v[i]]%2)
            {
                newMask=newMask|(1<<i);
            }
        }
        // cout<<i<<" "<<newMask<<endl;
        maskk[i]=newMask;   
    }
    int mm=(1<<(m+1));
    mm--;
    vector<vector<int>>dp(72,vector<int>(mm+1,-1));
    function<int(int,int)>f=[&](int i,int mask)->int{
        if(i==71)
        {
            // cout<<mask<<endl;
            for(int j=0;j<20;j++)
            {
                if(mask&(1<<j))
                return 0;
            }
            return 1;
        }
        if(dp[i][mask]!=-1)
        return dp[i][mask];
        int res=0;
        // cout<<mp2[i]<<endl;
        if(mp2[i]==0)
        res=f(i+1,mask);
        else if(mp2[i]%2==0)
        res=ways[mp2[i]-1]*f(i+1,mask);
        else
        {
            int newMask=mask;
            for(int j=0;j<20;j++)
            {
                if((mask&(1<<j))>0 && (maskk[i] & (1<<j))>0)
                {
                    newMask=newMask&~(1<<j);
                } 
            }
            res=ways[mp2[i]-1]*f(i+1,newMask);
        }
        return dp[i][mask]= res;
    };
    int x=f(1,0);
    cout<<x-1<<endl;
}