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
long long make_query(long long a,long long b)
{
    cout<<"?"<<" "<<a<<" "<<b<<endl;

    long long codeforcesInput;
    cin>>codeforcesInput;
    return codeforcesInput;
}
void solve()
{
    long long low=2;
    long long high=999;

    long long res=-1;
    function<long long(long long,long long)>f=[&](long long mid1,long long mid2)->long long{

        long long a=make_query(mid1,mid2);
        // debug(a,mid*mid);
        if((a)==(mid1*mid2))
        {
            return 2;
        }
        else if(a==(mid1*(mid2+1)))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };
    int count=0;
    while(low<=high)
    {
       long long mid1=low+(high-low)/3;
       long long mid2=low+2*(high-low)/3;
       int x=f(mid1,mid2);
       if(x==2)
       {
          res=mid2;
          low=mid2+1;
       }
       else if(x==1)
       {
           res=mid1;
           low=mid1+1;
           high=mid2-1;
       }
       else
       {
         high=mid1-1;
       }
    }
    if(res==-1)
    {
      cout<<"! "<<2<<endl;  
      return;
    }
    cout<<"! "<<res+1<<endl;
}