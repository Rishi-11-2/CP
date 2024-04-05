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
//(data type to be stored (pair,long long int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong long ints)
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
        solve();
}
void solve()
{
    long long int a,b,c;
    cin>>a>>b>>c;
    // cout<<c<<endl;
    string xa="";
    string ya="";
    long long int resx=0;
    long long int resy=0;
    for(long long int i=60;i>=0;i--)
    {
        long long int x=(1LL<<i);
        // debug(x);
        if((x&c)!=0)
        {
            // debug(x&c);
            if(a>b)
            {
                resx=resx+(1LL<<i);
                a--;
            }
            else
            {
               resy=resy+(1LL<<i);
                b--;
            }
            // pos=1-pos;
        }
    }
    // debug(a,b);

    // debug(a,b);
    for(long long int i=0;i<=60;i++)
    {
        long long int x=(1LL<<i);

        if(((x&(c))!=0) || ((resx&(x))!=0) || ((resy&x)!=0))
        {
            continue;
        }

        if(a>0 && b>0)
        {
                resx=resx+(1LL<<i);
               resy=resy+(1LL<<i);
                a--;
                b--;
        }
        else if(a==0 && b==0)
        {
            break;
        }
        else
        {
            cout<<-1<<endl;
            return;
        }
    }
    if(a>0 || b>0)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<resx<<" "<<resy<<endl;
    // long long int x=resx^resy;
    // cout<<x<<endl;
}