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
    int t = 1;
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
    int x=0;
    set<int>s;
    multiset<int>ss;
    for(int i=1;i<=n;i++)
    {
        x=x^i;
        s.insert(i);
        ss.insert(i);
    }

    int sum=0;
    while((int)s.size()>1)
    {
        // for(auto it:s)
        // cout<<it<<" ";
        // cout<<endl;
        auto z=*s.rbegin();
        ss.erase(ss.find(z));
        if(ss.find(z)==ss.end())
        s.erase(z);
        x=x^z;
        // debug(z);
        int res=-1;
        int x1=0;
        for(auto it:ss)
        {
            // cout<<it<<" ";
            int y=it-(x^it);
            // debug(x,it,y,x^it);
            if((y>=res) && (((x^(it-y))^it)==0))
            {
                x1=it;
                res=y;
            }
        }
        // cout<<endl;
        debug(x1,res);
        // if(res==-1)
        // {

        //     break;
        // }
        ss.erase(ss.find(x1));
        if(ss.find(x1)==ss.end())
        s.erase(x1);
        s.insert(x1-res);
        ss.insert(x1-res);
        for(auto it:ss)
        cout<<it<<" ";
        cout<<endl;
        // debug(it);
        // break;
        x=0;
        sum+=res;
    }

    cout<<sum<<endl;

}