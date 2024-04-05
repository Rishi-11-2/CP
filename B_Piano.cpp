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
        solve();
}
void solve()
{
    string s="wbwbwwbwbwbw";
    string res="";
    for(long long i=1;i<=(long long)(1e5);i++)
    {
        res+=s;
    }
    long long w,b;
    cin>>w>>b;
    long long i=0;
    long long j=0;
    long long n=res.length();
    long long x=0;
    long long y=0;

    function<long long(void)>check=[&](void)->long long{

        if(x==w && y==b)
        return 1;

        return 0;
    };
    function<long long(void)>f=[&](void)->long long{

        if(x<=w && y<=b)
        return 1;

        return 0;
    };
    while(j<n)
    {
        if(res[j]=='w')
        x++;
        if(res[j]=='b')
        y++;
        while(i<=j && !f())
        {
            if(res[i]=='w')
            x--;
            if(res[i]=='b')
            y--;
            i++;
        }
        if(check())
        {
            // debug(i,j,res.substr(i,j-i+1));
            cout<<"Yes"<<endl;
            return;
        }
        j++;
    }
    cout<<"No"<<endl;
}