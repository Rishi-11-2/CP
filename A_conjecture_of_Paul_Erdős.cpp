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
vector<int>countM;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int m=(int)(1e7);
    vector<bool>isPrime(m+1,1);
    isPrime[0]=isPrime[1]=0;
    for(long long i=2;i*i<=m;i++)
    {
        if(isPrime[i])
        {
            for(long long j=i*i;j<=m;j+=i)
            {
                isPrime[j]=0;
            }
        }
    }
    countM.assign(m+1,0);
    for(int x=0;x*x<=m;x++)
    {
        for(int y=0;y*y*y*y<=m;y++)
        {
            int num=x*x+y*y*y*y;
            if(num>m)
            continue;
            if(isPrime[num])
            {
                countM[num]=1;
            }
        }
    }
    for(int i=0;i<=m;i++)
    {
        countM[i]+=countM[i-1];
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin>>n;
    cout<<countM[n]<<endl;
}