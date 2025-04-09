#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
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

    vector<long long>left;
    vector<long long>right;

    long long x=(long long)(1e12);
    long long flag=0;
    long long sum=0;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        if(abs(arr[i])!=1)
        {
            x=arr[i];
            flag=1;
            continue;
        }
        if(!flag)
        {
            left.push_back(arr[i]);
        }
        else
        {
            right.push_back(arr[i]);
        }
    }
    long long n1=(long long)left.size();

    long long l1=0;
    long long r1=0;
    
    long long i=0;
    long long maxm=0;
    long long minm=0;
    long long p=0;
    while(i<n1)
    {
       
        p+=left[i];
        l1=min(l1,p-maxm);
        r1=max(r1,p-minm);

        maxm=max(maxm,p);
        minm=min(minm,p);

        i++;
    }

    i=0;
    maxm=0;
    minm=0;
    p=0;
    long long n2=(long long)right.size();

    long long l2=0;
    long long r2=0;

    // debug(n1,n2);
    while(i<n2)
    {
        p+=right[i];


        l2=min(l2,p-maxm);
        r2=max(r2,p-minm);

        maxm=max(maxm,p);
        minm=min(minm,p);

        i++;
    }
    // debug(l2,r2);
    set<long long>s;
    if(x!=(long long)(1e12))
    {
        // debug(x)
        // 
        long long rl1=0;
        long long rr1=0;
        reverse(all(left));
        // debug(ss);
        i=0;
        long long ss=0;
        while(i<n1)
        {
            long long j=i;
            long long sum=0;
            while(i<n1 && (left[i]==left[j]))
            {
                sum+=left[i];
                i++;
            }
            ss+=sum;
            // rl1=min(rl1,sum);
            rl1=min(rl1,ss);
            // rr1=max(rr1,sum);
            rr1=max(rr1,ss);
        }
        ss=0;
        long long rl2=0;
        long long rr2=0;
        i=0;
        while(i<n2)
        {
            long long j=i;
            long long sum=0;
            while(i<n2 && (right[i]==right[j]))
            {
                sum+=right[i];
                i++;
            }
            ss+=sum;
            rl2=min(rl2,ss);
            rr2=max(rr2,ss);
        }
        // debug(rl1,rr1);
        // debug(rl2,rr2);
        for(long long i=rl1+rl2;i<=rr1+rr2;i++)
        {
             s.insert(i+x);
        }
    }

    
    if(x!=(long long)(1e12))
    s.insert(x);

    for(long long i=l1;i<=r1;i++)
    s.insert(i);

    for(long long i=l2;i<=r2;i++)
    s.insert(i);

    s.insert(sum);
    cout<<(long long)s.size()<<endl;

    for(auto it:s)
    {
        cout<<it<<" ";
    }

    cout<<endl;

}