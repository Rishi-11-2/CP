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
    long long t;
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
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    multiset<long long>left;
    multiset<long long>right;

    left.insert(arr[0]);
    for(long long i=1;i<n;i++)
    right.insert(arr[i]);
    
    long long res=-1;
    for(long long i=1;i<n-1;i++)
    {
        auto it1=left.lower_bound(arr[i]);
        right.erase(right.find(arr[i]));
        auto it2=right.lower_bound(arr[i]);
        for(auto it:left)
        cout<<it<<" ";
        cout<<endl;
        for(auto it:right)
        cout<<it<<" ";
        cout<<endl;
        if(it1==left.begin())
        {
            left.insert(arr[i]);
             continue;
        }
        if(it2==right.begin())
        {
            left.insert(arr[i]);
            continue;
        }
        it1--;
        it2--;
        debug(i,*it1,*it2);
        vector<long long>v1;
        v1.push_back(*it1);
        v1.push_back(*it2);
        v1.push_back(arr[i]);
        sort(all(v1));
        // debug(v1[0],v1[1],v1[2]);
        res=max(res,((v1[0]+v1[1])*v1[2]));
        left.insert(arr[i]);
    }

    if(res==-1)
    {
        cout<<"NA"<<endl;
    }
    else
    {
        cout<<res<<endl;
    }

}