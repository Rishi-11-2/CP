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
    vector<pair<long double,long double>>v;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        long double a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    long double low=0;
    long double error=0.0000001;
    long double high=1e6;

    function<int(long double)>f=[&](long double mid)->int{

        priority_queue<long double ,vector<long double>,greater<long double>>pq;
        for(int i=0;i<k;i++)
        {
            pq.push(v[i].first-v[i].second*mid);
        }
        for(int i=k;i<n;i++)
        {
            long double x=v[i].first-v[i].second*mid;
            if(x>pq.top())
            {
                pq.pop();
                pq.push(x);
            }
        }
        long double sum=0;
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        if(sum>=0)
        return 1;
        return 0;
    };
    /* search space = 10^6 * (1/p)*/
    /* p=upto six decimal places  */
    /* search space=(10^6*10^6)=10^12  */
    /* log2(10^12)= 12/(0.3)= 40  */
    int count=0;
    long double res=high;
    while(high-low>=error)
    {
        long double mid=(low+high)/2;
        if(f(mid))
        {
            res=mid;
            low=mid+error;
        }
        else
        {
            high=mid-error;
        }
        if(count>60)
        break;
        count++;
    }
    cout<<res<<endl;

}