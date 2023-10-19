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
void solve()
{
      long long n,c,d;
    cin>>n>>c>>d;
      long long a[n];
    for(  long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,greater<  long long>());
    // if(a[0]>=c)
    // {
    //     cout<<"Infinity"<<endl;
    //     return;
    // }
    function<  long long(  long long)>f=[&](  long long mid)->  long long{
          long long s=0;
          long long curr=0;
          long long k=mid+1;
         long long i=0;
        while(i<d)
        {
            s+=a[curr];
            curr++;
            k=max(k-1,0LL);
            if(curr==n||k==0)
            {
                if(k>0)
                {
                    // cout<<k<<endl;
                    i+=(k+1);
                }
                else
                i++;
                k=mid+1;
                curr=0;
            }
            else
            i++;
        }
        // cout<<mid<<" "<<s<<endl;
        if(s>=c)
        return 1;
       return 0;
    };
      long long low=0;
      long long high=d;
      long long res=(  long long)(1e17);
    while(low<=high)
    {
          long long mid=(low+high)/2LL;
        // cout<<mid<<endl;
        // if(mid==1)
        // cout<<f(mid)<<endl;
        if(f(mid))
        {
            res=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(res==(  long long)(1e17))
    {
        cout<<"Impossible"<<endl;
        return;
    }
    else if(res>=d)
    {
        cout<<"Infinity"<<endl;
    }
    else
    cout<<res<<endl;
    
}