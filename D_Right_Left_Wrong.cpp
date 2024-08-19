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
    vector<long long>prefix(n,0);
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        prefix[i]=arr[i];
        if(i)
        {
            prefix[i]+=prefix[i-1];
        }
    }
    
    string s;
    cin>>s;

    vector<long long>left;
    vector<long long>right;
    // debug(s);
    for(long long i=0;i<n;i++)
    {
        if(s[i]=='L')
        {
            left.push_back(i);
        }
        else
        {
            right.push_back(i);
        }
    }
    // reverse(a)
    long long n1=(long long)left.size();
    long long n2=(long long)right.size();
    long long i=0;
    long long j=n2-1;
    // debug(n1,n2);
    long long ans=0;
    while(i<n1 && j>=0)
    {
        if(left[i]<right[j])
        {
            // debug(j);
            ans+=prefix[right[j]];
            if(left[i])
            ans-=prefix[left[i]-1];
            i++;
            j--;
        }
        else
        break;
    }

    cout<<ans<<endl;
}