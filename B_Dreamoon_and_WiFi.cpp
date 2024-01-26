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
    cout.precision(20);
        solve();
}
void solve()
{
    string x1;
    cin>>x1;
    string x2;
    cin>>x2;
    int l=0;
    for(char c:x1)
    {
        if(c=='+')
        l++;
        if(c=='-')
        l--;
    }
    int n=x1.length();
    int tc=0;
    for(char c:x2)
    {
        if(c=='?')
        tc++;
    }
    int count=0;
    // debug(x2);
    function<void(int,int)>f=[&](int i,int r)->void{
        if(i==n)
        {
            if(l==r)
            count++;
            return;
        }
        if(x2[i]=='+')
        {
            f(i+1,r+1);
        }
        else if(x2[i]=='-')
        {
            f(i+1,r-1); 
        }
        else
        {
            f(i+1,r-1);
            f(i+1,r+1);
        }
    };
    f(0,0);
    tc=(1<<tc);
    // debug(count);
    long double p1=(long double)(count);
    long double p2=(long double)(tc);
    long double x=(p1/p2);
    cout<<x<<endl;
}