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



    string s=to_string(n);
    long long len=s.length();
    vector<long long>v;
    long long ss=9;
    for(char c:s)
    {
        if(c=='7')
        {
            cout<<0<<endl;
            return;
        }
    }
    for(long long i=1;i<=len;i++)
    {
        v.push_back(ss);
        ss=ss*10+9;
    }
    long long res=INT_MAX;
    for(auto it:v)
    {
        // debug(it);
        long long x=n;
        long long count=0;
        int flag=0;
        while(!flag)
        {
            string a=to_string(x);
            set<char>as(all(a));
            if(as.find('7')!=as.end())
            {
                res=min(res,count);
                flag=1;
                break;
            }
            count++;
            x+=it;
        }
    }
    cout<<res<<endl;
}