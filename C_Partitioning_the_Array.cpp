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
vector<long long>spf;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long m=100000;
    spf.assign(m+1,0);

    for(long long i=0;i<=m;i++)
    {
        spf[i]=i;

    }
    for(long long i=4;i<=m;i+=2)
    spf[i]=2;
    for(long long i=3;i*i<=m;i++)
    {
        if(spf[i]==i)
        {
            for(long long j=i*i;j<=m;j+=i)
            {
                if(spf[j]==j)
                spf[j]=i;
            }
        }
    }
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
    {
        cin>>arr[i];
    }
    // debug(spf[2]);
    long long count=0;
    // if((odd==n||even==n) && n>1)
    // count++;
    for(long long i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            long long flag1=0;
            set<long long>x;
            for(long long j=0;j<i;j++)
            {
               set<long long>ad;
                long long k=j;
                while(k<n)
                {
                    ad.insert(arr[k]);
                    // prev=arr[k];
                    k+=(i);
                }
                long long prev=-1;
                for(auto it:ad)
                {
                    // cout<<it<<" ";
                    if(prev==-1)
                    {
                        prev=it;
                    }
                    else
                    {
                        x.insert(spf[it-prev]);
                        prev=it;
                    }
                }
                // cout<<endl;
            }
            if((long long)(x.size())>1 ||(!x.empty() &&  *x.begin()==1))
            {
                flag1=1;
                // break;
            }
            if(!flag1)
            count++;

        //    debug(i,count);
           if(n/i==n && (n)>1)
           {
            // debug(i,count);
              count++;
              continue;
           }

        //    debug(i);

           long long flag2=0;
           set<long long>y;
           for(long long j=0;j<(n/i);j++)
            {
                set<long long>bd;
                long long k=j;
                long long prev=-1;
                while(k<n)
                {
                    bd.insert(arr[k]);
                    k+=(n/i);
                }
                for(auto it:bd)
                {
                    
                    if(prev==-1)
                    {
                        prev=it;
                    }
                    else
                    {
                        y.insert(spf[it-prev]);
                        prev=it;
                    }
                }
            }
            if((long long)(y.size())>1 ||(!y.empty() && *y.begin()==1))
            {
                flag2=1;
            }
            if(!flag2 && (n/i)!=i)
            count++;
        }
    }
    cout<<count<<endl;
}