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
    long long n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    
    set<long long>st;
    for(long long i=0;i<n;i++)
    st.insert(i);

    while((long long)(st.size())>0 && k>0)
    {
        long long i=*st.begin();
        long long x=s[i]-'a';
        if(x>k)
        x=k;
        char c=(char)(s[i]-x);
        char maxm=s[i];
        long long diff=x;
        // debug(c,diff);
        for(long long j=0;j<n;j++)
        {
            long long y=s[j]-'a';
            if(y>k)
            break;
            
            char d=(char)(s[j]-y);
            if(d==c)
            {
            //    debug(d,y);
               maxm=max(maxm,s[j]);
               diff=max(diff,y);
            }
        }
        // debug(k);
        for(long long j=0;j<n;j++)
        {
            if(st.find(j)==st.end())
            continue;
            if(s[j]<=maxm )
            {
                s[j]=min(s[j],c);
                st.erase(j);
            }
        }
        // debug(diff);
        k-=diff;
        // debug(k);
    }
    cout<<s<<endl;
}