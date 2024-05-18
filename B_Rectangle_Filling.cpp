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
    int n,m;
    cin>>n>>m;

    char grid[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    set<char>s1;
    set<char>s2;
    for(int i=0;i<m;i++)
    {
        s1.insert(grid[0][i]);
        s2.insert(grid[n-1][i]);
    }
    set<char>s3;
    set<char>s4;
    for(int i=0;i<n;i++)
    {
        s3.insert(grid[i][0]);
        s4.insert(grid[i][m-1]);
    }
    if((int)(s3.size())==1 && (int)(s4.size())==1)
    {
        if(*s3.begin()!=*s4.begin())
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    if((int)(s1.size())==1 && (int)(s2.size())==1)
    {
        if(*s1.begin()!=*s2.begin())
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}