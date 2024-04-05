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
    long long n,m,k;
    cin>>n>>m>>k;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    
    long long d[m];
    for(long long i=0;i<m;i++)
    cin>>d[i];
    
    long long f[k];
    for(long long i=0;i<k;i++)
    cin>>f[i];


    sort(d,d+m);
    sort(f,f+k);

    multiset<long long,greater<long long>>ss;
    for(long long i=0;i<n-1;i++)
    {
        ss.insert(a[i+1]-a[i]);
    }

    long long maxm=*ss.begin();

    ss.erase(ss.begin());
    long long smaxm=*ss.begin();

    if(smaxm==maxm)
    {
        cout<<smaxm<<endl;
        return;
    }

    long long idx=-1;
    set<long long>s;
    for(long long i=0;i<n;i++)
    {
        if(a[i+1]-a[i]==maxm)
        {
            idx=i;
            break;
        }
    }
    for(long long i=0;i<k;i++)
    {
        s.insert(f[i]);
    }
    long long low=0;
    long long high=maxm;
    long long res=maxm;

    function<long long(long long)>f1=[&](long long mid)->long long{

        for(long long i=0;i<m;i++)
        {
            long long x=mid+a[idx]-d[i];
            long long y=a[idx+1]-(d[i]+mid);

            auto it=s.lower_bound(x);
            if(it==s.end())
            continue;

            if(*it>x)
            {
                it--;
            }
            int aa=*it;
            debug(mid,x,y,aa);
            if(aa>=y && aa<=x)
            {
                return 1;
            }

        }
        return 0;
    };
    while(low<=high)
    {
        long long mid=(low+high)/2;
        int x=f1(mid);
        if(x)
        {
            debug(x,mid);
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    cout<<max(res,smaxm)<<endl;
    
}