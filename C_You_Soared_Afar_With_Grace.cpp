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

    int a[n];

    map<int,int>pos;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }

    int b[n];
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        mp[b[i]]=i;
    }
    int count=0;
    int idx=-1;
    for(int i=0;i<n;i++)
    {
        int x=abs(i-mp[a[i]]);
        if(x==0)
        {
            count++;
            idx=i;
        }
    }

    if(n%2)
    {
        if(count>1 || count<1)
        {
            cout<<-1<<endl;
            return;
        }
    }
    else
    {
        if(count>0)
        {
            cout<<-1<<endl;
            return;
        }
    }
    
    vector<pair<int,int>>v;
    if(n%2 && (idx!=(n/2)))
    {
        swap(a[idx],a[n/2]);
        swap(b[idx],b[n/2]);

        mp[b[idx]]=idx;
        mp[b[n/2]]=n/2;

        pos[a[idx]]=idx;
        pos[a[n/2]]=n/2;
        v.push_back({idx,n/2});
    }

    set<int>s;
    for(int i=1;i<=n;i++)
    {
        s.insert(i);
    }
    for(auto it:s)
    {
        if(b[mp[it]]!=a[n-mp[it]-1])
        {
            int x=pos[it];
            int y=n-mp[it]-1;

            swap(a[pos[it]],a[n-mp[it]-1]);
            swap(b[pos[it]],b[n-mp[it]-1]);

            v.push_back({pos[it],n-mp[it]-1});
            
            pos[a[y]]=y;
            pos[a[x]]=x;

            mp[b[y]]=y;
            mp[b[x]]=x;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[n-i-1] || a[n-i-1]!=b[i])
        {
            cout<<-1<<endl;
            return;
        }
    }

    cout<<(int)v.size()<<endl;

    for(auto it:v)
    {
        cout<<it.first+1<<" "<<it.second+1<<endl;
    }
   
    
}