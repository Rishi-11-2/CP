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
    long long binpow(long long a,long long b,long long p)
    {
        long long res=1;
        while(b>0)
        {
            if(b&1)
            {
                res=((res%p)*(a%p))%p;
            }
            a=((a%p)*(a%p))%p;
            b>>=1;
        }
        return res;
    }
    void solve()
    {
        map<long long,long long>mp;
        long long n,p,k;
        cin>>n>>p>>k;
        long long a[n];
        for(long long i=0;i<n;i++)
        {
            cin>>a[i];
            long long x=a[i];
            long long y=binpow(x,4,p)-((k%p)*(x%p))%p;
            if(y<0)
            {
                y+=p;
            }
            else
            y=y%p;
            mp[y]++;
        }
        long long count=0LL;
        for(auto it:mp)
        {
            // cout<<it.first<<" "<<it.second<<endl;
            if(it.second>1)
            count+=((it.second)*(it.second-1))/(2*1LL);
        }
        cout<<count<<endl;
    }