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

    vector<vector<long long>>v;
    for(long long i=0;i<n;i++)
    {
        vector<long long>x;
        char c;
        cin>>c;
        if(c=='+')
        x.push_back(1);
        else
        x.push_back(2);

        long long d;
        cin>>d;
        x.push_back(d);

        cin>>c;
        if(c=='+')
        x.push_back(1);
        else
        x.push_back(2);

        cin>>d;
        x.push_back(d);

        v.push_back(x);

    }
    vector<long long>x;
    x.push_back(0);
    x.push_back(0);
    x.push_back(0);
    x.push_back(0);

    v.push_back(x);

    vector<long long>idx(n+1,0);
    idx[n]=1;
    for(long long i=n-1;i>=0;i--)
    {
        idx[i]=idx[i+1];

        if(v[i][0]==2 && v[i][2]==2)
        {
            if(v[i][1]==v[i][3])
            continue;

            else if(v[i][1]>v[i][3])
            idx[i]=1;

            else
            idx[i]=2;
        }
        else if(v[i][0]==2)
        {
            idx[i]=1;
        }
        else if(v[i][2]==2)
        {
            idx[i]=2;
        }
    }
    // for(long long i=0;i<n;i++)
    // cout<<suffix1[i]<<" ";

    // cout<<endl;

    // for(long long i=0;i<n;i++)
    // cout<<suffix2[i]<<" ";

    // cout<<endl;
    long long a=1;
    long long b=1;
    for(long long i=0;i<n;i++)
    {
        
        long long extra=0;
        if(v[i][0]==1)
        {
            extra+=v[i][1];
        }
        else
        {
            extra+=(a)*(v[i][1]-1);
        }
        if(v[i][2]==1)
        {
            extra+=v[i][3];
        }
        else
        {
            extra+=(b)*(v[i][3]-1);
        }


        if(idx[i+1]==1)
        {
            a+=extra;
        }
        else
        {
            b+=extra;
        }
        // debug(a,b);
    }
    
    cout<<(a+b)<<endl;
}