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
    
    vector<long long>suffix(n,0);
    vector<long long>prefix(n,0);
    vector<long long>notequal(n,0);

    prefix[0]=arr[0];
    for(long long i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+arr[i];
    }
    suffix[n-1]=arr[n-1];

    for(long long i=n-2;i>=0;i--)
    {
        suffix[i]=suffix[i+1]+arr[i];
    }

    notequal[0]=0;
    for(long long i=1;i<n;i++)
    {
        notequal[i]=notequal[i-1];
        if(arr[i]!=arr[i-1])
        notequal[i]+=1;
    }
    function<long long(long long)>l=[&](long long i)->long long{

        long long low=0;
        long long high=i-1;

        long long res=-1;

        while(low<=high)
        {
            long long mid=(low+high)/2;
            if((suffix[mid]-suffix[i])>arr[i])
            {
                if(notequal[i-1]-notequal[mid]==0)
                {
                    if(arr[i-1]>arr[i])
                    return (i-1);
                    else
                    high=mid-1;
                }
                else
                {
                    res=mid;
                    low=mid+1;
                }
            }
            else
            {
                high=mid-1;
            }
        }
        // debug(res,i);
        return res;
    };
    function<long long(long long)>r=[&](long long i)->long long{

        long long low=i+1;
        long long high=n-1;

        long long res=-1;

        while(low<=high)
        {
            long long mid=(low+high)/2;

            if((prefix[mid]-prefix[i])>arr[i])
            {
                if(notequal[i+1]-notequal[mid]==0)
                {
                    if(arr[i+1]>arr[i])
                    {
                        return (i+1);
                    }
                    else
                    {
                        low=mid+1;
                    }
                }
                else
                {
                    res=mid;
                    high=mid-1;
                }
            }
            else
            {
                low=mid+1;
            }
        }
        // debug(res,i);
        return res;
    };
    vector<long long>res;
    for(long long i=0;i<n;i++)
    {
        long long left=-1;
        long long right=-1;
        if(i>=1)
        {
            left=l(i);
        }
        if(i<n-1)
        {
            right=r(i);
        }
        if(left==-1 && right==-1)
        {
            res.push_back(-1);
        }
        else if(right==-1)
        {
            res.push_back(abs(left-i));
        }
        else if(left==-1)
        {
            res.push_back(abs(right-i));
        }
        else
        {
            res.push_back(min(abs(left-i),abs(right-i)));
        }
    }

    for(auto it:res)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}