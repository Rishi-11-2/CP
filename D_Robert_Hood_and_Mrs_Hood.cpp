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
void solve(long long);
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;
    cin >> t;
    long long count=1;
    while (t--)
    {
        solve(count);
        count++;
    }
}
void solve(long long cc)
{
    long long n,d,k;
    cin>>n>>d>>k;

    vector<pair<long long,long long>>jobs;
    long long idx=0;
    long long jdx=0;
    for(long long i=1;i<=k;i++)
    {
        long long l,r;
        cin>>l>>r;
        jobs.push_back({l,r});
    }
    sort(all(jobs));
    long long i=1;
    long long j=1;
    long long count=0;
    long long bc=0;
    long long mc=INT_MAX;
    long long bs=0;
    long long ms=0;
    multiset<int>s;
    while(j<=n)
    {
        while(jdx<k && j>=jobs[jdx].first)
        {
            count++;
            s.insert(jobs[jdx].second);
            jdx++;
        }
        long long len=j-i+1;
        while(i<=j && (len)>d)
        {
            i++;
            len=(j-i+1);
            while((int)s.size()>0 && i>*s.begin())
            {
                count--;
                s.erase(s.begin());
            }
        }
        len=(j-i+1);
        if(len==d)
        {
            //   debug(i,j,count);
            if(count<mc)
            {
                mc=count;
                ms=i;
            }
            if(count>bc)
            {
                bc=count;
                bs=i;
            }
        }
        j++;
    }
    cout<<bs<<" "<<ms<<endl;
   
}