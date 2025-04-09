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

    int arr[2*n];

    for(int i=0;i<2*n;i++)
    {
        cin>>arr[i];
    }

    map<int,set<int>>first;
    map<int,set<int>>last;

    map<int,int>mp;

    vector<int>v(n+1,1);
    for(int i=0;i<2*n;i++)
    {
        if(mp.find(arr[i])==mp.end())
        {
            if((i+1)<2*n)
            {
                first[arr[i]].insert(arr[i+1]);
            }
            if((i-1)>=0)
            {
                first[arr[i]].insert(arr[i-1]);
            }
            if(first[arr[i]].find(arr[i])!=first[arr[i]].end())
            {
                v[arr[i]]=0;
            }
        }
        else
        {
            if((i+1)<2*n)
            {
                last[arr[i]].insert(arr[i+1]);
            }
            if((i-1)>=0)
            {
                last[arr[i]].insert(arr[i-1]);
            }
            if(last[arr[i]].find(arr[i])!=last[arr[i]].end())
            {
                v[arr[i]]=0;
            }
        }

        mp[arr[i]]=1;
    }
    int count=0;
    set<pair<int,int>>s;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0)
        continue;
        for(auto it:last[i])
        {
            if(i>=it)
            continue;
            if(v[it]==0)
            continue;
            if(first[i].find(it)!=first[i].end())
            {
                // debug(i,it);
                s.insert({i,it});
            }
        }
    }


    for(auto it:s)
    {
        // debug(it.first,it.second);
        int i=it.first;
        int j=it.second;

        if((first[i].find(j)!=first[i].end()) && (last[i].find(j)!=last[i].end()) && (first[j].find(i)!=first[j].end()) && (last[j].find(i)!=last[j].end()) )
        {
            count++;
        }
    }
    // count=(int)s.size();

    cout<<(count)<<endl;
}