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
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    set<int>s;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]=0;
        s.insert(arr[i]);
    }

    // sort(all(arr));

    for(int i=0;i<n;i++)
    {
        char ch;
        cin>>ch;

        int l,r;
        cin>>l>>r;

        if(ch=='+')
        {
            
             s.erase(r);
            //  mp[r]++;
             s.insert(r+1);
            if(r>l)
            {
                s.erase(r-1);
                s.insert(r);
            }
        }
        else
        {
            
            s.erase(r);
             s.insert(r-1);
            if(r>l)
            {
                s.erase(r-1);
                s.insert(r);
            }
        }

        cout<<*s.rbegin()<<" ";
    }
    cout<<endl;

}