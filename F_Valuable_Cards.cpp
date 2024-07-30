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

long long m=(long long)(3e5)+10;
vector<long long>spf(m+1,1);
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t;
    cin >> t;
    for(long long i=1;i<m;i++)
    {
        spf[i]=i;   
    }
    for(long long i=2;i*i<=m;i++)
    {
        if(spf[i]==i)
        {
            for(long long j=2*i;j<=m;j+=i)
            {
                spf[j]=i;
            }
        }
    }
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n,x;
    cin>>n>>x;
    long long arr[n];
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<long long>div(m+1,0);
    for(long long i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            div[i]=1;
            div[x/i]=1;
        }
    }

    long long i=0;
    long long j=0;
    long long count=1;
    long long k=x;
    multiset<long long>s;
    while(j<n)
    {
        if(div[arr[j]])
        {
            long long flag=0;
            long long y=x/arr[j];
            multiset<long long>ss;
            while(y!=1)
            {
                if(s.find(y)!=s.end())
                {
                    flag=1;
                    break;
                }
                if(s.find(spf[y])==s.end())
                break;
                s.erase(s.find(spf[y]));
                ss.insert(spf[y]);
                y=y/spf[y];
            }
            if(flag||y==1)
            {
                count++;
                ss.clear();
                s.clear();
            }
            for(auto it:ss)
            {
                s.insert(it);
            }
            s.insert(arr[j]);
        }
        j++;
    }
    cout<<count<<endl;

}