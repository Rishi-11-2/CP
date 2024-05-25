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

    int arr[n+1];

    for(int i=1;i<=n;i++)
    cin>>arr[i];


    vector<int>res1(n+1,0);
    vector<int>res2(n+1,0);


    set<int>s1;
    set<int>idx;

    for(int i=1;i<=(n/2)+1;i++)
    {
        idx.insert(i);
        s1.insert(i);
    }

    set<int>s2;
    for(int i=(n/2)+2;i<=n;i++)
    {
        s2.insert(i);
        idx.insert(i);
    }
    
    for(int i=2;i<n;i+=2)
    {
        idx.erase(i);
        res1[i]=*s2.rbegin();
        s2.erase(*s2.rbegin());
        if(idx.find(i-1)!=idx.end())
        {
            res1[i-1]=*s1.begin();
            s1.erase(*s1.begin());
            idx.erase(i-1);
        }
        if(idx.find(i+1)!=idx.end())
        {
            res1[i+1]=*s1.begin();
            s1.erase(*s1.begin());
            idx.erase(i+1);
        }
    }

    for(auto i:idx)
    {
        res1[i]=*s1.begin();
        s1.erase(s1.begin());
    }

    s1.clear();
    s2.clear();
    idx.clear();

    for(int i=1;i<=(n/2)+1;i++)
    {
        idx.insert(i);
        s1.insert(i);
    }

    for(int i=(n/2)+2;i<=n;i++)
    {
        s2.insert(i);
        idx.insert(i);
    }
    
    for(int i=3;i<n;i+=2)
    {
        idx.erase(i);
        res2[i]=*s2.rbegin();
        s2.erase(*s2.rbegin());
        if(idx.find(i-1)!=idx.end())
        {
            res2[i-1]=*s1.begin();
            s1.erase(*s1.begin());
            idx.erase(i-1);
        }
        if(idx.find(i+1)!=idx.end())
        {
            res2[i+1]=*s1.begin();
            s1.erase(*s1.begin());
            idx.erase(i+1);
        }
    }

    for(auto i:idx)
    {
        res2[i]=*s1.begin();
        s1.erase(s1.begin());
    }

    int count1=0;

    int count2=0;

    for(int i=2;i<n;i+=2)
    {
        if((res1[i]+arr[i])>(res1[i-1]+arr[i-1]) && (res1[i]+arr[i])>(res1[i+1]+arr[i+1]))
        {
            count1++;
        }
    }
    for(int i=3;i<n;i+=2)
    {
        if((res1[i]+arr[i])>(res1[i-1]+arr[i-1]) && (res1[i]+arr[i])>(res1[i+1]+arr[i+1]))
        {
            count2++;
        }
    }

    if(count1==(n/2)-1)
    {
        // debug("hi");
        for(int i=1;i<=n;i++)
        cout<<res1[i]<<" ";
        cout<<endl;
        return;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<res2[i]<<" ";
    }
    cout<<endl;
}