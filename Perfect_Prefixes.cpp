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

    vector<long long>arr(n);

    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    long long count=1;
    if(n%2==0)
    {
        auto v=arr;
        long long c=1;
        long long i=1;
        while(i<n)
        {
            if((i+1)==v[i])
            {
                i++;
                break;
            }
            if((i+1)<n && v[i+1]<v[i])
            {
                swap(v[i],v[i+1]);
                i+=2;
            }
            else
            {
                break;
            }
        }
        long long count=0;

        set<long long>s;
        for(long long i=0;i<n;i++)
        {
            s.insert(v[i]);
            if((*s.rbegin())<=(i+1))
            count++;
        }
        cout<<count<<endl;
    }
    else
    {
        auto v1=arr;
        long long i=0;
        while(i<n)
        {
            if(v1[i]==(i+1))
            {
               break;
            }
            if((i+1)<n && v1[i+1]<v1[i])
            {
                swap(v1[i],v1[i+1]);
                i+=2;
            }
            else
            break;
        }

        // for(long long i=0;i<n;i++)
        // {
        //     cout<<v1[i]<<" ";
        // }
        // cout<<endl;
        auto v2=arr;
        i=0;
        while(i<n)
        {
            if(v2[i]==(i+1))
            {
                i++;
                break;
            }
            if(v2[i+1]<v2[i])
            {
                swap(v2[i],v2[i+1]);
                i+=2;
            }
            else
            break;
        }

        long long count1=0;
        long long count2=0;

        set<long long>s;
        for(long long i=0;i<n;i++)
        {
            s.insert(v1[i]);
            if((*s.rbegin())<=(i+1))
            count1++;
        }

        s.clear();
        for(long long i=0;i<n;i++)
        {
            s.insert(v2[i]);
            if((*s.rbegin())<=(i+1))
            count2++;
        }
        // for(long long i=0;i<n;i++)
        // {
        //     cout<<v2[i]<<" ";
        // }
        // cout<<endl;
        // debug(count1,count2);
        cout<<max(count1,count2)<<endl;
    }
}