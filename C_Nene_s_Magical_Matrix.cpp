#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;

    long long s=0;
    vector<vector<long long>>v;
    long long i=n-1;
    long long j=n-1;
    long long turn=2;
    long long a[n][n];
    long long count=0;
    while(i>=0 || j>=0)
    {
        vector<long long>x;
        x.push_back(turn);
        if(turn ==2)
        {
            x.push_back(j+1);
            for(long long k=0;k<n;k++)
            {
                a[k][j]=k+1;
            }
            j--;
        }
        else
        {
            x.push_back(i+1);
            for(long long k=0;k<n;k++)
            {
                a[i][k]=k+1;
            }
            i--;
        }
        for(long long k=1;k<=n;k++)
        {
            x.push_back(k);
        }
        v.push_back(x);
        if(turn ==2)
        turn = 1;
        else
        turn = 2;
        count++;
    }

    long long sum=0;
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<n;j++)
        sum+=a[i][j];
    }
    cout<<sum<<" "<<count<<endl;
    for(auto it:v)
    {
        for(auto i:it)
        cout<<i<<" ";
        cout<<endl;
    }
}