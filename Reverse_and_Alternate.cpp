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
bool check(string &s)
{
    int n=s.length();
    int prev=0;
    int flag=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[prev])
        flag=1;
        prev=i;
    }

    return (flag==0);
}
void solve()
{

    int n;
    cin>>n;

    string s;
    cin>>s;



    int left=-1;
    int right=-1;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            left=i;
            break;
        }
    }

    for(int i=n-2;i>=0;i--)
    {
        if(s[i]==s[i+1])
        {
            right=i;
            break;
        }
    }

    if(left==-1 && right==-1)
    {
        cout<<"Yes"<<endl;
        return;
    }
    string z=s.substr(left,right-left+1);

    reverse(all(z));
    string s1=s.substr(0,left);

    s1+=z;

    string z1=s.substr(right+1);
    s1+=z1;


    string x=s.substr(left);

    reverse(all(x));
    string s2=s.substr(0,left)+x;


    string y=s.substr(0,right+1);
    string s3=s.substr(right+1);
    reverse(all(y));
    s3=y+s3;

    // debug(left,right);
    

    if(check(s)||check(s1)||check(s2)||check(s3))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }


}