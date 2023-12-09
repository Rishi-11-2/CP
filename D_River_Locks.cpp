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
void solve()
{
    /* Simple Intuition based. Does not even require DP. Can be solved easily by the concept of volumes
    We just need to take care of the the minimum time required to fill all the locks if 
    all the pipes are opened . Thats it .  for each query greater than the minimum time
    we can simply divide it by the time to fill all the locks and it will give the numebr of pipes*/
    long long n;
    cin>>n;
    long long arr[n];
    long long minm=0;
    long long s=0;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
        minm=max(minm,(s+i)/(i+1));
    }
    // cout<<minm<<endl;
    long long q;
    cin>>q;
    for(long long i=0;i<q;i++)
    {
        long long x;
        cin>>x;
        if(x<minm)
        cout<<-1<<endl;
        else
        {
            long long y=s/x;
            if(s%x)
            y++;
           cout<<y<<endl;
        }
    }
}
