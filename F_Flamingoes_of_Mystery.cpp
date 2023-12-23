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
    cout<<"?"<<" "<<l<<" "<<r<<endl;
    int codeforcesOutput;
    cin>>codeforcesOutput;
    return codeforcesOutput;
}
void solve()
{
    int n;
    cin>>n;
    int prefix[n];

   for(int i=1;i<n;i++)
   {
      int x=make_query(1,i+1);
    //   cout<<x<<endl;
      prefix[i]=x;
   }   
   int y=make_query(2,3);
   prefix[0]=prefix[2]-y;
   int arr[n];
   arr[0]=prefix[0];
   for(int i=1;i<n;i++)
   {
      arr[i]=prefix[i]-prefix[i-1];
   }
   cout<<"!"<<" ";
   for(int i=0;i<n;i++)
   {
    cout<<arr[i]<<" ";
   }
   cout<<endl;
}