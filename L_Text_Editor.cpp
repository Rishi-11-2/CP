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
struct Hashing{
    vector<long long>hash;
    vector<long long>base_pow;
    long long mod=(long long)(1e9)+7;
    long long p=9971;
    string s;
    long long n;
    Hashing(const string &a)
    {
        s=a;
        n=s.length();

        hash.resize(n+1,0);
        base_pow.resize(n+1,0);

        base_pow[0]=1;
        hash[0]=1;

        for(long long i=1;i<=n;i++)
        {
            base_pow[i]=(p*base_pow[i-1])%mod;
            hash[i]=((p*hash[i-1])%mod+s[i-1]+997)%mod;
        }
    }
    long long get_hash(long long l,long long r)
    {
        long long h=hash[r+1]-(hash[l]*base_pow[r-l+1])%mod;
        if(h<0)
        h+=mod;

        return h;
    }
};
void solve()
{
    string text;
    getline(cin,text);

    string pattern;

    getline(cin,pattern);

    long long n;
    cin>>n;


   
    Hashing h1(text);

    Hashing h2(pattern);

    int n1=text.size();
    int n2=pattern.size();
    int low=1;

    int high=n2;
    int res=0;
    function<int(int )>f=[&](int mid)->int{
    long long x=h2.get_hash(0,mid-1);

    int count=0;
      for(int i=0;i+mid-1<n1;i++)
      {
         if(x==h1.get_hash(i,i+mid-1))
          count++;
      }  

    //   debug(mid,count);
      if(count>=n)
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

    if(res==0)
    {
        cout<<"IMPOSSIBLE"<<endl;

    }
    else
    {
        // debug(res);
        cout<<pattern.substr(0,res)<<endl;
    }


}