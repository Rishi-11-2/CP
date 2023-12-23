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
    cin>>t;
    while(t--)
    {
        solve();

    }
    
}
vector<int>make_query(int l,int r)
{
    cout<<"? "<<l+1<<" "<<r+1<<endl;
    vector<int>v;
    for(int i=l;i<=r;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);

    }
    return v;
}
void solve()
{
    int n;
    cin>>n;


    int low=0;
    int high=n-1;
    int res=n;
    while(low<=high)
    {
        int mid=(low+high)/2;

        auto v1=make_query(low,mid);

        int count1=0;
        for(auto it:v1)
        {
            // cout<<it<<" ";
            if(it>=(low+1) && (it)<=(mid+1))
            count1++;
        }
        // debug(count1,count2);
        if(count1%2)
        {
            res=mid;
            high=mid-1;
        }
        else 
        {
            res=mid+1;
            low=mid+1;
        }
    }

    cout<<"! "<<res+1<<endl;
}