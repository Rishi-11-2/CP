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
    int n,k,m;
    cin>>n>>m>>k;
        int count=0;
    count+=min(n-1,m);
        count+=(m/n);
    if(k>3)
    {
        cout<<0<<endl;
        return ;
    }
    if(k==1)
    {
        cout<<1<<endl;
        return;
    }
    if(k==2)
    {
        
        cout<<count<<endl;
    }
    else if(k==3)
    {
        cout<<(m+1)-(count+1)<<endl;
    }

}