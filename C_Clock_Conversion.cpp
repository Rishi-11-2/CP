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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    string s;
    cin>>s;

    string hr=s.substr(0,2);
    string mm=s.substr(3);
    int a=stoi(hr);
    int b=stoi(mm);
    int flag=0;
    if(a==12)
    {
        flag=1;
    }
    if(a==0)
    {
        a=12;
    }
    else if(a>12)
    {
        flag=1;
        a=a-12;
    }
    string ss="AM";
    if(flag)
    {
        ss="PM";
    }
    string x=to_string(a);
    if(x.length()==1)
    {
        char c='0';
        x=c+x;
    }
    cout<<x<<":"<<mm<<" "<<ss<<endl;
}