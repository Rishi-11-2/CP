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
    long long a,b;
    cin>>a>>b;
    long long xk,yk;
    cin>>xk>>yk;
    long long xq,yq;
    cin>>xq>>yq;

    long long aa[]={2,2,-2,-2,1,-1,1,-1};
    long long bb[]={1,-1,1,-1,2,2,-2,-2};
   long long count=0;
   set<pair<long long,long long>>s;
    for(long long i=0;i<8;i++)
    {
        long long x,y;
        if(abs(aa[i])==2)
        {
            x=a*((aa[i]<0)?-1:1);
            y=b*((bb[i]<0)?-1:1);
        }
        else
        {
            x=b*((bb[i]<0)?-1:1);
            y=a*((aa[i]<0)?-1:1);
        }
        for(long long j=0;j<8;j++)
        {
            long long x1,y1;
            if(abs(aa[j])==2)
            {
                x1=a*((aa[j]<0)?-1:1);
                y1=b*((bb[j]<0)?-1:1);
            }
            else
            {
                x1=b*((bb[j]<0)?-1:1);
                y1=a*((aa[j]<0)?-1:1);
            }
            // cout<<x<<" "<<y<<" "<<x1<<" "<<y1<<endl;
            long long r1=xk+x+x1;
            long long r2=yk+y+y1;
            // cout<<r1<<" "<<r2<<endl;
            if(r1==xq && r2==yq)
            {
                s.insert({xk+x,yk+y});
            }
        }
        
    }
    cout<<(long long)(s.size())<<endl;
}