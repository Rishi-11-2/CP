#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
        
        long long sum=n*(n+1);
        sum=sum/2LL;
        
        long long squaresum = n*(n+1)*(2*n+1);
        
        squaresum=squaresum/6LL;
        
        long long totalsum=0;
        long long totalsquaresum=0;
        for(int i=0;i<n;i++)
        {
            totalsum+=abs(arr[i]);
            totalsquaresum+=arr[i]*arr[i];
        }
        long long x=totalsum-sum;
        long long y=totalsquaresum-squaresum;
        
        long long twice = (y/x)+x;
        
        twice=twice/2LL;
        
        long long missing=(y/x)-x;
        missing=missing/2LL;
        

        cout<<twice<<" "<<missing<<endl;
}