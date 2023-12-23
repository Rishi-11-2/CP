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
    
        solve();
    
}
int make_query(int l,int r)
{
    if(l>=r)
    return -1;

    cout<<"? "<<l+1<<" "<<r+1<<endl;
    int codeforcesOutput;
    cin>>codeforcesOutput;
    return codeforcesOutput-1;
}
void solve()
{
    int n;
    cin>>n;
    int low=0;
    int high=n-1;
    int res=n;
    while(low<high)
    {
        int mid=(low+high)/2;
        int smax=make_query(low,high);
        if(smax<=mid)
        {
            int idx=make_query(low,mid);
            if(idx==smax)
            high=mid;
            else
            {
                low=mid+1;
            }
        }
        else
        {
            int idx=make_query(mid+1,high);
            if(idx==smax)
            low=mid+1;
            else
            high=mid;
        }
    }
    cout<<"! "<<low+1<<endl;
}