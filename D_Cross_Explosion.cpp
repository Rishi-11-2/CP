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
void solve()
{
    int h,w,q;
    cin>>h>>w>>q;
    vector<set<int>>row(h+1);
    vector<set<int>>col(w+1);

    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            row[i].insert(j);
        }
    }
    for(int j=1;j<=w;j++)
    {
        for(int i=1;i<=h;i++)
        {
            col[j].insert(i);
        }
    }

    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        if(row[x].find(y)!=row[x].end())
        {
            row[x].erase(y);
            col[y].erase(x);
            continue;
        }

        // left
        auto it1=row[x].upper_bound(y);
        if(it1!=row[x].begin())
        {
            it1--;
            col[*it1].erase(x);
            row[x].erase(*it1);
        }
        // right
        auto it2=row[x].lower_bound(y);
        if(it2!=row[x].end())
        {
            col[*it2].erase(x);
            row[x].erase(it2);
        }
        // up
        auto it3=col[y].upper_bound(x);
        if(it3!=col[y].begin())
        {
            it3--;
            row[*it3].erase(y);
            col[y].erase(it3);
        }
        // down
        auto it4=col[y].lower_bound(x);
        if(it4!=col[y].end())
        {
            row[*it4].erase(y);
            col[y].erase(it4);
        }
    }

    int count=0;
    for(int  i=1;i<=h;i++)
    {
        count+=(int)row[i].size();
    }

    cout<<count<<endl;
}