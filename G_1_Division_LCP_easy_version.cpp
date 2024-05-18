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
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();










const long long mod1=(long long)(1e9+7);
const long long mod2=(long long)(1e9+1);
const long long mod3=(long long)(1e15+5);
const long long p1=uniform_int_distribution<long long>(0,mod1-1)(rng);
const long long p2=uniform_int_distribution<long long>(0,mod2-1)(rng);
const long long p3=999119999;
struct Hash{

    long long *pref1;
    // vector<long long>hash;
    long long *base_pow1;
    long long *base_pow2;
    long long *pref2;
    string s;
    long long n;
    Hash(const string &a)
    {
        s=a;
        n=s.length();
        pref1=(long long*)(malloc((n+1)*sizeof(long long)));
        pref2=(long long*)(malloc((n+1)*sizeof(long long)));
        base_pow1=(long long*)(malloc((n+1)*sizeof(long long)));
        base_pow2=(long long*)(malloc((n+1)*sizeof(long long)));
        base_pow1[0]=1;
        base_pow2[0]=1;
        pref1[0]=1;
        pref2[0]=1;
        for(long long i=1;i<=n;i++)
        {
            base_pow1[i]=(p1*base_pow1[i-1])%mod1;
            base_pow2[i]=(p2*base_pow2[i-1])%mod2;
            pref1[i]=((pref1[i-1]*p1)%mod1+s[i-1]+997)%mod1;
            pref2[i]=((pref2[i-1]*p2)%mod2+s[i-1]+997)%mod2;
        }
    }

    long long get_hash(long long l,long long r)
    {
        long long h1=pref1[r+1]-(pref1[l]*base_pow1[r-l+1])%mod1;
        long long h2=pref2[r+1]-(pref2[l]*base_pow2[r-l+1])%mod2;
        if(h1<0)
        h1+=mod1;
        
        if(h2<0)
        h2+=mod2;
        long long h3=(h1*p1)%mod3;
        h3=(h3+h2)%mod3;
        return h3;
    }

};






signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,l,r;
    cin>>n>>l>>r;

    string s;
    cin>>s;
    int low=1;
    int high=n/l;

    int res=0;

    Hash h(s);
    function<int(int)>f=[&](int mid)->int{

        long long h1=h.get_hash(0,mid-1);

        int i=mid;
        int count=1;
        while(i+mid<=n)
        {
            long long h2=h.get_hash(i,i+mid-1);
            if(h2==h1)
            {
                count++;
                i=i+mid;
            }
            else
            {
                i++;
            }
        }

        if(count>=r)
        return 1;
        return 0;
    };
    while(low<=high)
    {
        int mid=(low+high)/2;

        if(f(mid))
        {
            res=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<res<<endl;
}