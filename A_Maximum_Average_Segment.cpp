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
    int n,d;
    cin>>n>>d;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
     
     int start=-1;
     int end=-1;
    long double error=0.0000001;
    long double low=-1;
    long double high=1000;
    long double res=high;
    int l=-1;
    int r=-1;
     function<int(long double)>f=[&](long double mid)->int{

        // debug(mid);
        long double c[n];
        for(int i=0;i<n;i++)
        {
            c[i]=((arr[i]*1.0)-mid);
            // cout<<c[i]<<" ";
        }
        // cout<<endl;
        vector<long double>prefix(n,0.0);
        vector<long double>min_pref(n,0.0);
        vector<int>idx(n,0);
        prefix[0]=c[0];
        min_pref[0]=prefix[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+c[i];
            if(min_pref[i-1]<=prefix[i])
            {
                idx[i]=idx[i-1];
            }
            else
            {
                idx[i]=i;
            }
            min_pref[i]=min(min_pref[i-1],prefix[i]);
        }
        /*for the first loop we are checking the entire segment(0,i) , therefore there can be cases 
        which we are missing out on*/
        for(int i=d-1;i<n;i++)
        {
            if(prefix[i]>=0)
            {
                start=0;
                end=i;
                return 1;
            }
        }
        for(int i=d;i<n;i++)
        {
            // debug(prefix[i]-min_pref[i-(d)]);
            if(prefix[i]-min_pref[i-(d)]>=0)
            {
                start=idx[i-(d)]+1;
                end=i;
                return 1;
            }
        }
        return 0;
     }; 
    while(high-low>=error)
    {
        long double mid=(low+high)/2;
        if(f(mid))
        {
            // debug(mid,start,end);
            l=start;
            r=end;
            res=mid;
            low=mid+error;
        }
        else
        {
            high=mid-error;
        }
    }
    // cout<<f(6.6)<<endl;
    // cout<<res<<endl;
    
    cout<<l+1<<" "<<r+1<<endl;
}