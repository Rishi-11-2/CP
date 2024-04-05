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
    int n;
    cin>>n;
    string s;
    cin>>s;

    vector<int>one(n+1,0);
    vector<int>zero(n+1,0);
    for(int i=1;i<=n;i++)
    {
        one[i]=one[i-1];
        zero[i]=zero[i-1];

        if(s[i-1]=='1')
        one[i]++;
        if(s[i-1]=='0')
        zero[i]++;
    }
    // debug(one[n]);
    vector<pair<double,int>>v;
    for(int i=0;i<=n;i++)
    {
        int y=i;
        int z=(n-i);
        int y1=(y+2-1)/2;
        int z1=(z+2-1)/2;
        // debug(zero[i],y1,one[i],one[n],z1);
        if(zero[i]>=y1 && (one[n]-one[i])>=z1)
        {
            double c=(n/(2.0));
            c=abs(c-i);
            // debug(c,i);
            v.push_back({c,i});
        }
    }
    sort(all(v));
    cout<<v[0].second<<endl;
}