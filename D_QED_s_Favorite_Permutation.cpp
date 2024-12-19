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
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    string s;
    cin>>s;
    set<int>ss;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='L' && s[i+1]=='R')
        {
            ss.insert(i);
        }
    }
    int d=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=(i+1))
        {
            d=i;
            break;
        }
    }
    // debug(d);
    for(int i=1;i<=q;i++)
    {
        int j;
        cin>>j;
        j--;
        if(s[j]=='L')
        {
            s[j]='R';
        }
        else
        {
            s[j]='L';
        }
        ss.erase(j);
        if((j+1)<n && s[j]=='L' && s[j+1]=='R')
        {
            ss.insert(j);
        }
        if(j>0)
        {
            if(s[j-1]=='L' && s[j]=='R')
            {
                ss.insert(j);
            }
        }
        // debug(idx);
        if((int)ss.size()==0||d==-1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            if(d<idx)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                cout<<"YES"<<endl;
            }
        }
    }
}