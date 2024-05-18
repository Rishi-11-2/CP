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
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
        solve();
}
void solve()
{
    int n;
    cin>>n;

    int count1=0;
    int count2=0;
    int count3=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            count1++;
        }
        else if(x==2)
        {
            count2++;
        }
        else
        {
            count3++;
        }
    }
    /*-

_0, 1-->(x), 2-->(y), 3-->(z) => expected value = sum of ( probability of event + the value of that event )

E(a[x, y, z]) = 1+ p0 * E[a[x, y, z]] + p1 * E[a[x-1, y, z]] + p2* E[a[x+1, y-1,z]] +
 p3 * E[a[x, y+1, z]] ;

p0,01,p2, p3 : they  are the probabilities of events occuring 

p1 = x/n

p2=(y/n)

p3=(z/n)

p0=((n-(x+y+z))/n)
*/
    double nn=n*1.0;
    vector<vector<vector<double>>>dp(400,vector<vector<double>>(400,vector<double>(400,-1.0)));
    function<double(int,int,int)>f=[&](int a,int b,int c)->double{
        if(a==0 && b==0 && c==0)
        {
            return 0;
        }

        if(dp[a][b][c]!=-1)
        return dp[a][b][c];
        double res=0.0;

        double p0=((n-(a+b+c))*1.0)/nn;
        double p1=(a*1.0)/nn;
        double p2=(b*1.0)/nn;
        double p3=(c*1.0)/nn;
        double zero=0.0;
        double res1=0.0;
        double res2=0.0;
        double res3=0.0;
        // debug(p1,p2,p3,p0);
        if(p1>zero)
        {
            res1=p1*f(a-1,b,c);
        }
        if(p2>zero)
        {
            res2=p2*f(a+1,b-1,c);
        }
        if(p3>zero)
        {
            res3=p3*f(a,b+1,c-1);
        }
        res=1+res1+res2+res3;
        // debug(res1,res2,res3);
        double x=(1.0)-p0;
        res=(res/x);
        // debug(res);

        return dp[a][b][c]= res;
    };

    double x=f(count1,count2,count3);

    cout<<x<<endl;
}