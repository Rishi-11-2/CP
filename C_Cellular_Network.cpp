#include <bits/stdc++.h>
using namespace std;
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
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
    long long  n,m;
    cin>>n>>m;
    long long  a[n];
    long long  b[m];
    for(long long  i=0;i<n;i++)
    cin>>a[i];
    for(long long  j=0;j<m;j++)
    cin>>b[j];
    
    sort(a,a+n);
    sort(b,b+m);
    // for(int i=0;i<m;i++)
    // cout<<b[i]<<endl;
    if(n<=m)
    {
        long long  i=0;
       long long j=0;
       while(i<n && j<m)
       {
        // debug(i,j);
          if(a[i]==b[j])
          {
            i++;
            // j++;
          }
          else{
            j++;
          }
       }
       if(i==n)
       {
          cout<<0<<endl;
          return;
       }
    }
    function<long long (long long )>f=[&](long long  mid)->long long {

        long long  minm=b[0]-mid;
        long long  maxm=b[0]+mid;
        long long  i=0;
        long long  j=1;
        while(j<m)
        {
            // debug(mid,j);
            while(i<n)
            {
                if(a[i]>=minm && a[i]<=maxm)
                i++;
                else
                break;
            }
            maxm=b[j]+mid;
            minm=b[j]-mid;
            // debug(mid,maxm,minm,j,b[j]);
            j++;
        }
         while(i<n)
        {
            if(a[i]>=minm && a[i]<=maxm)
            i++;
            else
            break;
        }
        if(i==n)
        return 1;
        return 0;
    };
    long long  low=1;
    long long  high=(long long )(1e18);
    long long  res=high;
    // f(11);
    while(low<=high)
    {
        long long  mid=(low+high)/(2LL);
        // debug(mid,f(mid));
        if(f(mid))
        {
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    cout<<res<<endl;
}