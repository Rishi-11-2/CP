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
//(data type to be stored (pair,int ,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraint s)
typedef tree < pair<int ,int >, null_type,less<pair<int ,int >>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int  t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int  n,k,q;
    cin>>n>>k>>q;
    int  arr[n];
    vector<set<int >>prefix(n+1);
    vector<set<int >>suffix(n+1);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        if (i > 0) {
            prefix[i] = prefix[i - 1]; // Only access when i > 0
        }
        if (arr[i] % k == 0) {
            prefix[i].insert(arr[i]);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            suffix[i] = suffix[i + 1]; // Only access when i < n - 1
        }
        if (arr[i] % k == 0) {
            suffix[i].insert(arr[i]);
        }
    }

    for(int  i=1;i<=q;i++)
    {
        int  l,r;
        cin>>l>>r;
        l--;
        l=min(l,n-1);
        r=n-r;
        r=min(r,n-1);

         if(prefix[l]==suffix[r])
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
   
}