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
const long long mod1=(long long)(1e12+7);
const long long mod2=(long long)(1e11+1);
const long long mod3=(long long)(2e15+1);
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

    long long get_hash(long long l,long long r)
    {
        long long h1=pref1[r+1]%mod1-(pref1[l]%mod1*base_pow1[r-l+1]%mod1)%mod1;
        long long h2=pref2[r+1]%mod2-(pref2[l]%mod2*base_pow2[r-l+1]%mod2)%mod2;
        if(h1<0)
        h1+=mod1;
        
        if(h2<0)
        h2+=mod2;
        
        long long h3=h1+h2;
        if(h3>=mod3)
        h3-=mod3;
        return h3;
    }

};
// struct chash {
//     long long operator()(const pair<long long,long long>& x) const { return x.first* 31 + x.second; }
// };
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
        solve();
}
void solve()
{
    string a;
    cin>>a;
    string b;
    cin>>b;
    
    int n1=a.length();
    int n2=b.length();

    Hash h1(a);
    Hash h2(b);
   
   int low=1;
   int res=0;
   int high=min(n1,n2);

   while(low<=high)
   {
      int mid=(low+high)/2;
      
      gp_hash_table<long long,long long>mp;
       int flag=0;
    // unordered_map<long long,long long>mp2;
        // vector<pair<long long ,long long>>v;
        for(int i=0;i+mid-1<n1;i++)
        {
            auto x=h1.get_hash(i,i+mid-1);
            // debug(x,mid,1);
            // if(mp.find(x)==mp.end())
            mp[x]++;
        }
        // set<pair<long long,long long>>s(all(v));
        // vector<pair<long long ,long long>>v1;
        for(int i=0;i+mid-1<n2;i++)
        {
            auto x=h2.get_hash(i,i+mid-1);
            // debug(x,mid,2);
            if(mp[x]>0)
            {
                flag=1;
                break;
            }
        }
      if(flag)
      {
        // cout<<mid<<endl;
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