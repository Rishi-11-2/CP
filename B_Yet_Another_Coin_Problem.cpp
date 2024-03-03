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
    long long t;
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
    vector<long long>arr={1,3,6,10,15};
    long long res=INT_MAX;
    for(long long i=0;i<5;i++)
    {
        long long x=n;
        long long j=i;
        long long count=0;
        while(x>0)
        {
            while(j>=0 && arr[j]>x)
            {
                j--;
            }
            if(j<0)
            break;
            long long y=x/arr[j];
            x-=(y*arr[j]);
            count+=y;
            // debug(i,x,y);
        }
        res=min(res,count);
    }
    vector<int>vv={3,6,15};
    int z=(n/10);
    for(int i=0;i<=min(z,10);i++)
    {
        int y=n-(i*10);
        int j=2;
        long long count=i;
        // debug(y,i*10);
        while(y>0)
        {
            while(j>=0 && vv[j]>y)
            {
                j--;
            }
            if(j<0)
            break;
            int xx=(y/vv[j]);
            count+=xx;
            y-=(vv[j]*xx);
        }
        if(y>0)
        {
            count+=y;
        }
        // debug(count,i);
        res=min(res,count);
    }
    cout<<res<<endl;
}