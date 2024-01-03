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

    set<char>C;
    set<char>V;
    C.insert('b');
    C.insert('c');
    C.insert('d');
    V.insert('a');
    V.insert('e');
    vector<string>res;
    int i=n-1;
    int start=1;
    while(i>=0)
    {
        int len=0;
        int limit=3;
        if(V.find(s[i])!=V.end())
        limit=2;
        string z="";
        while(i>=0 && len<limit)
        {
            z+=s[i];
            i--;
            len++;
        }
        reverse(all(z));
        res.push_back(z);
    }
    reverse(all(res));
    int m=res.size();
    for(int i=0;i<m-1;i++)
    {
        cout<<res[i]<<".";
    }
    cout<<res[m-1]<<endl;
}