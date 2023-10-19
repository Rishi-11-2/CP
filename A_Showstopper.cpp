#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    cin>>b[i];
    int maxA=0;
    int maxB=0;
    for(int i=0;i<n;i++)
    {
        maxA=max(maxA,a[i]);
        maxB=max(maxB,b[i]);
    }
    int maxm=min(maxA,maxB);
    for(int i=0;i<n;i++)
    {
        if(b[i]<a[i])
        {
            int t=a[i];
            a[i]=b[i];
            b[i]=t;
        }
    }
    int n_maxA=0;
    int n_maxB=0;
    for(int i=0;i<n;i++)
    {
        n_maxA=max(n_maxA,a[i]);
        n_maxB=max(n_maxB,b[i]);
    }
    if(n_maxA==a[n-1] && n_maxB==b[n-1])
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}