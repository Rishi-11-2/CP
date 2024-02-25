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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;

    vector<int>res(n+1,0);

    int i=1;
    int sc=1;
    int ec=n;
    while(i<=k)
    {
        int j=i;
        while(j<=n)
        {
            res[j]=sc;
            sc++;
            j+=k;
        }
        i+=2;
    }
    i=k;
    while(i>=1)
    {
        int j=i;
        while(j<=n)
        {
            res[j]=ec;
            ec--;
            j+=k;
        }
        i-=2;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;

}