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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
bool cmp(const pair<char,int>&a,const pair<char,int>&b)
{
    if(a.first==b.first)
    return a.second>b.second;

    return a.first>b.first;
}

bool cmp1(const pair<char,int>&a,const pair<char,int>&b)
{
    if(a.first==b.first)
    return a.second<b.second;

    return a.first<b.first;
}
void solve()
{
    string a;
    string b;
    cin>>a>>b;

    vector<pair<char,int>>down;
    vector<pair<char,int>>up;
    int n=(int)a.length();
    for(int i=0;i<n;i++)
    {
        if(a[i]>b[i])
        {
            // debug(i);
            down.push_back({a[i],i});
        }
        else if(a[i]<b[i])
        {
            up.push_back({a[i],i});
        }
    }

    // sort(all(down),cmp1);
    reverse(all(up));

    string s=a;
    vector<string>v;
    for(auto it:down)
    {
        // debug(it.second);
        s[it.second]=b[it.second];
        v.push_back(s);
    }

    for(auto it:up)
    {
        s[it.second]=b[it.second];
        v.push_back(s);
    }
    cout<<(int)v.size()<<endl;
    for(auto it:v)
    {
        cout<<it<<endl;
    }
}