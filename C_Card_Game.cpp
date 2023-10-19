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
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin>>n;
    int arr[n+1];
    int res=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(i>2)
        res=max(res,arr[i]);
        if(i>2)
        {
            res=max(res,arr[i]+arr[1]);
        }
    }
    // for(int i=0;i<=n;i++)/
    vector<int>odd;
    vector<int>even;
    for(int i=3;i<=n;i++)
    {
        if(i%2)
        {
            odd.push_back(arr[i]);
        }
        else
        {
            even.push_back(arr[i]);
        }
    }
    sort(odd.begin(),odd.end(),greater<int>());
    sort(even.begin(),even.end(),greater<int>());
    int minm=min((int)(odd.size()),(int)(even.size()));
    int sum=0;
    if(n>=2)
    res=max(res,max(arr[1]+arr[2],arr[1]));
    else if(n>=1)
    res=max(res,arr[1]);
    for(int i=0;i<minm;i++)
    {
        sum=max(sum,sum+odd[i]+even[i]+max(0,max(arr[1],max(arr[2],arr[1]+arr[2]))));
        res=max(res,sum);
    }
    cout<<res<<endl;
}