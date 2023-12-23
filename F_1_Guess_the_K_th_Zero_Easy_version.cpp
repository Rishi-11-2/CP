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
    cout<<"?"<<" "<<l+1<<" "<<r+1<<endl;
    int codeforcesOutput;
    cin>>codeforcesOutput;
    return codeforcesOutput;
}
void solve()
{
    int n,t;
    cin>>n>>t;
    int k;
    cin>>k;
    int low=0;
    int high=n-1;
    int res=high;

    function<int(int)>f=[&](int mid)->int{
        int sum=make_query(0,mid);
        int length=mid+1;
        // debug(sum,length,mid);
        if(length-sum>=k)
        {
            return -1;
        }
       else  if(length-sum<k)
        {
            return 1;
        }
        return 0;
    };
    while(low<=high)
    {
        int mid=(low+high)/2;
        int x=f(mid);
         if(x>0)
        {
            low=mid+1;
        }
        else
        {
            res=mid;
            high=mid-1;
        }
    }
    cout<<"! "<<res+1<<endl;
}
/* 0111*/