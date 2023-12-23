#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
    vector<long long>p(n);
    priority_queue<long long>pq1;
    for(long long i=0;i<n;i++)
    {
        cin>>p[i];
        pq1.push(p[i]);
    }
    long long x,a;
    cin>>x>>a;
    long long y,b;
    cin>>y>>b;
    long long k;
    cin>>k;
    vector<long long>v;
    function<long long(long long)>f=[&](long long mid)->long long{
        auto pq=pq1;
        long long hcf=(a*b)/(__gcd(a,b));
        long long i=hcf-1;
        v.assign(mid+1,-1);
        while(i<=mid)
        {
            // debug(i,hcf);
            v[i]=pq.top();
            pq.pop();
            i+=(hcf);
        }
        long long counter=0;
        if(x>y)
        {
            i=a-1;
            counter=a;
        }
        else
        {
            i=b-1;
            counter=b;
        }
        while(i<=mid)
        {
            if(v[i]==-1)
            {
                // debug(i,counter);
                v[i]=pq.top();
                pq.pop();
            }
            i+=counter; 
        }
        if(x>y)
        {
            i=b-1;
            counter=b;
        }
        else
        {
            i=a-1;
            counter=a;
        }
        while(i<=mid)
        {
            if(v[i]==-1)
            {
                // debug(i,counter);
              v[i]=pq.top();
              pq.pop();
            }
            i+=counter;
        }
        long long res=0;
        for(long long j=0;j<=mid;j++)
        {
            long long sum=0;
            if((j+1)%a==0)
            {
                sum=sum+(v[j]*x)/100;
            }
            if((j+1)%b==0)
            {
                sum=sum+(v[j]*y)/100;
            }
            // debug(mid,sum,j);
            res+=sum;
        }
        // debug(res);
        if(res>=k)
        return 1;
        return 0;
    };

    long long low=0;
    long long high=n-1;
    long long res=high+1;

    while(low<=high)
    {
        long long mid=(low+high)/2;
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
    // long long xx=f(5);
    // cout<<x<<endl;
    if(res==n)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<res+1<<endl;
}