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
void solve(int );
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;
    cin >> t;
    int c=0;
    while (t--)
    {
        solve((++c));
    }
}
void solve(int c)
{
    long long n;
    cin>>n;

    vector<long long>arr(2*n);

    for(long long i=0;i<2*n;i++)
    {
        cin>>arr[i];
    }

    vector<long long>left;
    vector<long long>right;
    set<long long>s;

    sort(arr.begin(),arr.end(),greater<long long>());
    long long lsum=0;
    long long rsum=0;
    vector<long long>res;
    for(long long i=0;i<2*n;i++)
    {
        s.insert(arr[i]);
        if(i%2)
        {
            rsum+=arr[i];
            right.push_back(arr[i]);
        }
        else
        {
            lsum+=arr[i];
            left.push_back(arr[i]);
        }
    }
    for(long long i=0;i<2*n;i++)
    {
        long long d1=0;
        long long d2=0;
        if(i%2)
        {
            d1=arr[i];
        }
        else
        {
            d2=arr[i];
        }
        rsum-=d1;
        lsum-=d2;
        long long d=rsum-lsum;
        if(((d+arr[i])>0) && (s.find(d+arr[i])==s.end()))
        {
            cout<<arr[i]<<" ";
            cout<<(d+arr[i])<<" ";
            // cout<<"h"<<endl;
            long long k1=0;
            long long k2=0;
            for(long long j=0;j<(2*n-1);j++)
            {
                if(j%2==0)
                {
                    auto it=right[k1++];
                    if(it==arr[i])
                    {
                        it=right[k1++];
                    }
                    res.push_back(it);
                }
                else
                {
                    auto it=left[k2++];
                    // cout<<it<<" ";
                    if(it==arr[i])
                    {
                        it=left[k2++];
                    }
                    res.push_back(it);
                }
            }
            for(auto it:res)
            cout<<it<<" ";
            cout<<"\n";
            return;
        }
        rsum+=d1;
        lsum+=d2;
    }
}