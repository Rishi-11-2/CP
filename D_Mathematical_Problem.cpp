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
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    map<int,vector<string>>mp;
    mp[3].push_back("169");
    mp[3].push_back("961");
    mp[3].push_back("196");

    for(int i=5;i<=n;i+=2)
    {
        for(auto it:mp[i-2])
        {
            mp[i].push_back(it+"00");
        }
        string s="1";
        int x=i-3;
        x=x/2;
        for(int j=1;j<=x;j++)
        {
            s+=(to_string(0));
        }
        s+="6";
        for(int j=1;j<=x;j++)
        {
            s+=(to_string(0));
        }
        s+="9";
        mp[i].push_back(s);

        string s1="9";
        for(int j=1;j<=x;j++)
        {
            s1+=(to_string(0));
        }
        s1+="6";
        for(int j=1;j<=x;j++)
        {
            s1+=(to_string(0));
        }
        s1+="1";
        mp[i].push_back(s1);
    }


    for(auto it:mp[n])
    {
        cout<<it<<endl;
    }
}