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
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==2)
    {
        if(s[0]=='0' && s[1]=='0')
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
        return ;
    }
    if(s[0]=='1'||s[n-1]=='1')
    {
        cout<<"YES"<<endl;
        return;
    }
    for(int i=0;(i+2)<n;i++)
    {
        if(s[i]=='0' && s[i+1]=='1' && s[i+2]=='1')
        {
            cout<<"YES"<<endl;
            return;
        }
        if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0')
        {
            cout<<"YES"<<endl;
            return;
        }

        if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='1')
        {
            cout<<"YES"<<endl;
            return;
        }

    }

    cout<<"NO"<<endl;
}