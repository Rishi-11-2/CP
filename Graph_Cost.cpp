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

    long long arr[n+1];
    for(long long i=1;i<=n;i++)
    cin>>arr[i];
     
    stack<pair<long long,long long>>st;

    for(long long i=1;i<n;i++)
    {
        while((int)(st.size())>=2 && st.top().first>arr[i])
        {
            int value=st.top().first;
            int index=st.top().second;
                st.pop();
            int value2=st.top().first;
                if(value<value2)
                {
                    st.push({value,index});
                    break;
                }
        }
        st.push({arr[i],i});
    }

     while((int)(st.size())>=2 && st.top().first>arr[n])
    {
        int value=st.top().first;
        int index=st.top().second;
         st.pop();
        int value2=st.top().first;
           if(value<value2)
            {
               st.push({value,index});
                break;
            }
    }
    long long cost=0;

    long long idx=n;
    while(!st.empty())
    {
        // debug(st.top().second);
        long long x=abs(idx-st.top().second)*max(arr[idx],st.top().first);
        idx=st.top().second;
        st.pop();
        cost+=x;
    }

    long long x=abs(idx-1)*max(arr[idx],arr[1]);
    cost+=x;

    cout<<cost<<endl;
}