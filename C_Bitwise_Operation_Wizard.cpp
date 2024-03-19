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
char make_query(int a,int b,int c,int d)
{
    cout<<"?"<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

    char codeforcesOuput;
    cin>>codeforcesOuput;

    return codeforcesOuput;
}
void solve()
{
    int n;
    cin>>n;
    
    pair<int,int>maxm;
    /*4
      1 0 2 3*/
    maxm.first=0;
    maxm.second=0;
    for(int i=1;i<n;i++)
    {
        char c=make_query(maxm.first,maxm.second,i,i);
        if(c=='<')
        {
            maxm.first=i;
            maxm.second=i;
        }
    }      
    pair<int,int>minm;
    minm.first=-1;
    minm.second=-1;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        if(i==maxm.first)
        continue;
        if(minm.first==-1)
        {
            v.push_back(i);
            minm.first=i;
            minm.second=i;
            continue;
        }
        char c=make_query(maxm.first,minm.first,maxm.first,i);
        if(c=='<')
        {
            v.clear();
            v.push_back(i);
            minm.first=i;
            minm.second=i;
        }
        else if(c=='=')
        {
            v.push_back(i);
        }
    }
    int x=v[0];
    for(int i=1;i<(int)(v.size());i++)
    {
        char c=make_query(x,x,v[i],v[i]);
        if(c=='>')
        {
            x=v[i];
        }
    }

    
    cout<<"!"<<" "<<maxm.first<<" "<<x<<endl;

}