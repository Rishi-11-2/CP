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
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;

    long long arr[n];
    

    priority_queue<long long>odd;
    priority_queue<long long>even;

    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];

        if(arr[i]%2)
        {
            odd.push(arr[i]);
        }
        else
        {
            even.push(arr[i]);
        }
    }

    long long c=(long long)even.size();

    if((long long)odd.size()==0)
    {
        cout<<even.top()<<endl;
        return;
    }
    if((long long)even.size()==0)
    {
        cout<<odd.top()<<endl;
        return;
    }
    while(!odd.empty() && !even.empty())
    {
        auto it1=odd.top();
        auto it2=even.top();
        odd.pop();
        even.pop();

        odd.push(it1+it2);
    }

    long long ans=odd.top();

    odd.pop();
    // debug(c);

    while(!odd.empty())
    {
        ans+=(odd.top()-1);
        odd.pop();
        c--;
    }

    cout<<ans<<endl;
}