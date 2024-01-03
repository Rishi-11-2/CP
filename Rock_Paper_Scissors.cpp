#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,char>mp;
    mp['S']='R';
    mp['P']='S';
    mp['R']='P';
    string z;
    string x="P";
    for(int i=0;i<n;i++)
    {
        z+=x;
    }
    int count=(n/2);
    count++;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R')
        count--;
        if(count==0)
        break;
    }
    // cout<<count<<endl;
    for(int i=n-1;i>=0;i--)
    {
        if(count==0)
        break;
        if(s[i]=='R')
        continue;
        
        z[i]=mp[s[i]];
        count--;
    }
    cout<<z<<endl;
}