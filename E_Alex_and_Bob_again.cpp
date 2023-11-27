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
    int a[n];
    int b[n];
     
    map<int,int>mp;
    for(int i=0;i<n;i++)
   {
       cin>>a[i];
       mp[a[i]]=i;
   }
   vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        v.push_back(mp[b[i]]);
    }
    int tail[n];
    int len=1;
    tail[0]=v[0];
    function<int(int,int)>f=[&](int i,int target)->int{

        int low=0;
        int high=i;
        int res=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(tail[mid]<target)
            {
                res=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    };
    for(int i=1;i<n;i++)
    {
        if(v[i]>=tail[len-1])
        {
            len++;
            tail[len-1]=v[i];
        }
        else
        {
            int c=f(len-1,v[i]);
            tail[c]=v[i];
        }
    }
    cout<<2*(n-len)<<endl;
}