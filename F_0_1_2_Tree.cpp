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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    
    int x=1;
    int counta=0;
    int countb=0;
    int countc=0;
    int xx=0;
    int ans=0;
    while(a>0)
    {
        if(x>a)
        {
            // flag=1;
            xx=x-a;
            countc+=a;
            counta+=a;
            break;
        }
        ans++;
        a-=x;
        counta+=x;
        x=x*2;
    }
    ans++;
    countc+=x;

    b-=min(b,x);
    countb=min(b,x);
    if(counta==a && countb==b && countc==c)
    {
        cout<<ans-1<<endl;
        return;
    }
    while(countb<b)
    {
        if(countc>b)
        {
            ans++;
            break;
        }
        countb+=countc;
        ans++;
    }

    // debug(counta,countb);
    cout<<ans-1<<endl;
}