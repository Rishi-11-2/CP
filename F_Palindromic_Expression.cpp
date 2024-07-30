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
bool valid(string &s)
{
    for(char c:s)
    {
        if(c=='0')
        return false;
    }
    return true;
}
bool check(long long n)
{
    string s=to_string(n);
    for(char c:s)
    {
        if(c=='0')
        return false;
    }
    long long i=0;
    long long j=s.length();
    j--;
    while(i<j)
    {
        if(s[i]!=s[j])
        return false;
        i++;
        j--;
    }
    return true;
}
gp_hash_table<long long,string>mp;
string  f(long long n)
{
    
    if(check(n))
    {
        // debug(n);
        return to_string(n);
    }
    if(mp.find(n)!=mp.end())
    return mp[n];
    for(long long i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            long long z=n/i;
            
            string ss=to_string(i);
            reverse(all(ss));
            long long a=stoll(ss);
            // debug(i,a);
            if(valid(ss) && z%a==0)
            {
                string  res=f(z/a);
                
                if((long long)res.size()!=0)
                {
                    res=to_string(i)+"*"+res+"*"+ss;
                    return mp[n]= res;
                }
            }
        }
    }
    return mp[n]= "";
}
void solve()
{
    
    long long n;
    cin>>n;
    string s=f(n);
    if(s.length()==0)
    cout<<-1<<endl;
    else
    cout<<s<<endl;
}