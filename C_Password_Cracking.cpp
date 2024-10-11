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
void solve()
{
    long long n;
    cin>>n;
    string s="";
    char ch1='0';
    char ch2='1';

    function<long long(string)>ask=[&](string s)->long long{
        
        cout<<"? "<<s<<endl;
        long long codeforcesOutput;
        cin>>codeforcesOutput;
        return codeforcesOutput;
    };
    while(s.length()<n)
    {
        s+=string(1,ch1);
        long long output=ask(s);
        if(output==1)
        {
            continue;
        }
        s.pop_back();
        s+=string(1,ch2);
        output=ask(s);
        if(output==1)
        {
            continue;
        }
        s.pop_back();
        break;
    }
    while(s.length()<n)
    {
        string z=string(1,ch1)+s;
        int output=ask(z);
        if(output==1)
        {
            s=z;
            continue;
        }
        z=string(1,ch2)+s;
        s=z;
    }
    cout<<"! "<<s<<endl;
}