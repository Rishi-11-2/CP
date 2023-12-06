#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
const long long mod=(long long)(1e9)+7;
void solve();
string findDiff(string str1, string str2) 
{ 
    // Before proceeding further, make sure str1 
    // is not smaller 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    long long n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    long long carry = 0; 
  
    // Run loop till small string length 
    // and subtract digit of str1 to str2 
    for (long long i = 0; i < n2; i++) { 
        // Do school mathematics, compute difference of 
        // current digits 
  
        long long sub 
            = ((str1[i] - '0') - (str2[i] - '0') - carry); 
  
        // If subtraction is less than zero 
        // we add then we add 10 long longo sub and 
        // take carry as 1 for calculating next step 
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of larger number 
    for (long long i = n2; i < n1; i++) { 
        long long sub = ((str1[i] - '0') - carry); 
  
        // if the sub value is -ve, then make it positive 
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long dp[(long long)(1e5)+1][2][13][2];
long long f(long long i,long long tight,long long prev,long long db,string &s,long long nr)
{
     if(i==nr)
        {
            return prev;
            // return 0;
        }
        if(dp[i][tight][prev+1][db]!=-1)
        return dp[i][tight][prev+1][db];
        long long low=0;
        long long high=(tight==1)?s[i]-'0':9;
        long long res=0;
        for(long long j=low;j<=high;j++)
        {
            long long newTight=0;
            if(tight==1)
            {
                if(j==high)
                newTight=1;
            }
            long long newPrev=j;
            long long newDb=1;
            long long x=(binpow(10,nr-i,mod)%mod*prev%mod)%mod;
            res=(res%mod+f(i+1,newTight,newPrev,newDb,s,nr)%mod);
            if(j==prev)
            continue;
            res=(res%mod+x%mod)%mod;
                // cout<<x<<endl;
        }

        return dp[i][tight][prev+1][db]=res%mod;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long nl,nr;
    cin>>nl;
    string l;
    l.assign(nl,'/');
    for(long long i=0;i<nl;i++)
    cin>>l[i];
    
    cin>>nr;
    string r;
    r.assign(nr,'/');
    for(long long i=0;i<nr;i++)
    cin>>r[i];
    string one;
    one.assign(1,'1');
    // while(one.length()<l.length())
    // {
    //     char c='0';
    //     one=c+one;
    // }
    string newL=findDiff(l,one);
    while(newL.length()<r.length())
    {
        char c='0';
        newL=c+newL;
    }

    // cout<<r<<" "<<newL<<endl;
    memset(dp,-1,sizeof(dp));
    long long rr=f(0,1,-1,0,r,nr);
    // long long ll=0;
    memset(dp,-1,sizeof(dp));
    long long ll=f(0,1,-1,0,newL,nr);
    // cout<<rr<<" "<<ll<<endl;
    cout<<(rr-ll)<<endl;
}