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
    int x;
    cin>>x;

    int k=x;

    vector<int>v(32,0);
    for(int i=0;i<32;i++)
    {
        if((x&(1<<i))!=0)
        v[i]=1;
    }
    int i=0;
    while(i<=31)
    {
        int j=i;
        if(v[i]==0)
        {
            i++;
            continue;
        }
        while(1)
        {
            j++;
            if(v[j]==0)
            break;
            v[j]=0;
        }
        if(i+1==j)
        {
            v[i]=1;
            i++;
            continue;
        }
        v[i]=-1;
        v[j]=1;
        i=j;
    }

    cout<<32<<endl;
    for(int i=0;i<32;i++)
    cout<<v[i]<<" ";
    cout<<endl;
}