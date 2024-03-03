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
       solve();
}
const long long mod1=(long long)(1e9+7);
const long long mod2=(long long)(1e9+1);
// const long long mod3=(long long)(2e15+1);
const long long p1=uniform_int_distribution<long long>(0,mod1-1)(rng);
const long long p2=uniform_int_distribution<long long>(0,mod2-1)(rng);
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
            base_pow1[i]=(p1%mod1*base_pow1[i-1]%mod1)%mod1;
            base_pow2[i]=(p2%mod2*base_pow2[i-1]%mod2)%mod2;
            pref1[i]=((pref1[i-1]%mod1*p1%mod1)%mod1+s[i-1]+997)%mod1;
            pref2[i]=((pref2[i-1]%mod2*p2%mod2)%mod2+s[i-1]+997)%mod2;
        }
    }

    pair<long long,long long> get_hash(long long l,long long r)
    {
        long long h1=pref1[r+1]%mod1-(pref1[l]%mod1*base_pow1[r-l+1]%mod1)%mod1;
        long long h2=pref2[r+1]%mod2-(pref2[l]%mod2*base_pow2[r-l+1]%mod2)%mod2;
        if(h1<0)
        h1+=mod1;
        
        if(h2<0)
        h2+=mod2;
        
        return make_pair(h1,h2);
    }

};
void solve()
{
    string s;
    cin>>s;
    long long n=s.length();
    Hash h(s);
    vector<int>prefixes;
    for(int i=1;i<=n;i++)
    {
        int a=n-i;
        auto x=h.get_hash(0,i-1);
        auto y=h.get_hash(n-i,n-1);
        if(x==y)
        prefixes.push_back(i);
    }
    // debug(n);
    long long low=0;
    long long high=(long long)(prefixes.size())-1;
    long long res=-1;
    function<long long(long long)>f=[&](long long mid)->long long{
        long long x=prefixes[mid];
        auto val1=h.get_hash(0,x-1);
        for(long long i=1;(i+x-1)<(n-1);i++)
        {
            auto val3=h.get_hash(i,i+x-1);
            // debug(i,i+mid-1,val3[0],val3[1]);
            if(val3==val1)
            return 1;
        }

        return 0;
    };
    while(low<=high)
    {
        long long mid=(low+high)/2LL;

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
    if(res==-1)
    {
        cout<<"Just a legend"<<endl;
    }
    else{
        cout<<s.substr(0,prefixes[res])<<endl;
    }

}