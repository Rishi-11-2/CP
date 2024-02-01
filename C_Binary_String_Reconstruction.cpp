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
    long long t;
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
    long long x;
    cin>>x;
    long long n=s.length();
    vector<long long>no(n+1,0);

    for(long long i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            long long j=i+1;

            if(j-x>=1)
            {
                no[j-x]=1;
            }
            if(j+x<=n)
            {
                no[j+x]=1;
            }
        }
    }
    vector<long long>yes(n+1,0);
    for(long long i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            long long j=i+1;
            if(j-x>=1 && !no[j-x])
            {
                yes[j-x]=1;
            }
            else if(j+x<=n && !no[j+x])
            {
                yes[j+x]=1;
            }
            else{
                cout<<-1<<endl;
                return ;
            }
        }
    }
    string res="";
    for(long long i=1;i<=n;i++)
    {
        if(yes[i])
        res+=to_string(1);
        else
        res+=to_string(0);
    }
    cout<<res<<endl;


}