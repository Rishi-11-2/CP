#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
class Hash{
    private:
    const long long mod1=(long long)(1e9)+7;
    const long long mod2=(long long)(1e9)+1;
    const long long mod3=(long long)(1e15)+5;
    
    const long long p1=1001;
    const long long p2=1003;
    
    const long long p3=99911;
    
    public:
    vector<long long>pref1;
    vector<long long>pref2;
    vector<long long>base_pow1;
    vector<long long>base_pow2;
    
    string s;
    long long n;
    
    Hash( string a)
    {
        s=a;
        n=s.length()+10;
        // debug(n);
        pref1.assign(n+1,0);
        pref2.assign(n+1,0);
        base_pow1.assign(n+1,0);
        base_pow2.assign(n+1,0);
        build();
    }
    void build()
    {
        base_pow1[0]=1;
        
        base_pow2[0]=1;
        pref1[0]=1;
        pref2[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            base_pow1[i]=(base_pow1[i-1]*p1)%mod1;
            base_pow2[i]=(base_pow2[i-1]*p2)%mod2;
            
            pref1[i]=((pref1[i-1]*p1)%mod1+s[i-1]+997)%mod1;
            
            pref2[i]=((pref2[i-1]*p2)%mod2+s[i-1]+997)%mod2;
        }
        
    }
    
    long long getHash(int l,int r)
    {
        long long h1=pref1[r+1];
        
        h1-=(pref1[l]*base_pow1[r-l+1])%mod1;
        h1=(h1%mod1+mod1)%mod1;
        
        long long h2=pref2[r+1];
        
        h2-=(pref2[l]*base_pow2[r-l+1])%mod2;
        
        h2=(h2%mod2+mod2)%mod2;
        
        long long h3=((h1*p3)%mod3+h2)%mod3;
        
        return h1;
    }
};
void solve()
{
    string str1,str2;
    cin>>str1>>str2;
            int n=str1.length();
        int m=str2.length();
        
        Hash h1(str1);
        Hash h2(str2);
        
        int low=1;
        int high=min(n,m);
        // cout<<n<<" "<<m<<endl;
        int res=0;
        function<int(int)>f=[&](int mid)->int{
            
            map<long long,long long>mp;
            for(int i=0;i+mid-1<n;i++)
            {
                long long h=h1.getHash(i,i+mid-1);
                // cout<<h<<endl;
                mp[h]=1;
            }
            // cout<<endl;
            for(int i=0;i+mid-1<m;i++)
            {
                long long h=h2.getHash(i,i+mid-1);
                // cout<<h<<endl;
                if(mp.find(h)!=mp.end())
                return 1;
            }
            return 0;
        };
        int x=f(3);
        // cout<<x<<endl;
        while(low<=high)
        {
            int mid=(low+high)/2;
            // cout<<mid<<endl;
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