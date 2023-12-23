#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
int make_query(int x)
{
    cout<<"? "<<x+1<<" ";
    for(int i=1;i<=x+1;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    int codeforcesOutput;
    cin>>codeforcesOutput;
    return codeforcesOutput;
}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>prefix(n,0);
    prefix[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        prefix[i]=arr[i]+prefix[i-1];
    }
    int low=0;
    int high=n;
    int res=low;
    function<int(int)>f=[&](int mid)->int{

        int s=make_query(mid);
        if(s>prefix[mid])
        {
            return 1;
        }
            return 0;
    };
    while(low<=high)
    {
        int mid=(low+high)/2;
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
    cout<<"! "<<res+1<<endl;
}