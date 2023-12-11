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
    long long n;
    cin>>n;
    long long arr[n];
    set<long long>s;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        s.insert(arr[i]);
    }
    if((long long)(s.size())==1)
    {
        cout<<0<<endl;
        return;
    }
    long long mx=*max_element(arr,arr+n);
    // cout<<mx<<endl;
    vector<long long>res;
    while((long long)(s.size())>1)
    {
        long long x=0;
        if(mx%2)
        {
            mx=(mx+0)/2LL;

        }
        else
        {
            x=1;
            mx=(mx+1LL)/2LL;
        }
        s.clear();
        for(long long i=0;i<n;i++)
        {
            arr[i]=(arr[i]+x)/2LL;
            s.insert(arr[i]);
            // cout<<arr[i]<<" ";

        }
        // cout<<endl;
        res.push_back(x);
    }
    cout<<(long long)(res.size())<<endl;
    if(!((long long)(res.size())>n))
    {
        for(auto it:res)
        cout<<it<<" ";
        cout<<endl;
    }
}