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
    
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int b[n];
    for(int i=0;i<n;i++)
    cin>>b[i];
    
    vector<vector<int>>v;
    for(int i=0;i<n;i++)
    {
        v.push_back({b[i],a[i],i});
    }
    vector<int>mp(n,0);
    sort(all(v));
    /*we are sorting according to b's because we need to equalize a to b . thats why we are sorting according to b not according to a
    as we need to make a's equal to b. once a[i] is increased , it can never decrease 
    therefore we are going from the minimum to maximum as we intend to increase a[i] to b[i] if they are not alreay equal*/
    for(auto it:v)
    {
        int idx=it[2];
        int flag=0;
        if(a[idx]==b[idx])
        {
            mp[idx]=1;
            continue;
        }
        for(int j=idx;j<n;j++)
        {
            if(a[j]>b[idx])
            break;
            
            if(mp[j]==1)
            {
                if(b[j]!=b[idx])
                break;
            }
            if(a[j]==b[idx])
            {
                mp[idx]=1;
                flag=1;
                break;
            }
        }
        if(flag==1)
        continue;
        for(int j=idx;j>=0;j--)
        {
            if(a[j]>b[idx])
            break;
            
            if(mp[j]==1)
            {
                if(b[j]!=b[idx])
                break;
            }
            if(a[j]==b[idx])
            {
                mp[idx]=1;
                flag=1;
                break;
            }
        }

        if(!flag)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    
}