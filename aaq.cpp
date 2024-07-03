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
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
        solve();
}
class Manacher{
   public:
   string t;
   vector<int>p;
   
   Manacher(string &s)
   {
       for(char c:s)
       {
           t+=string("#",1)+c;
       }
       t+=string("#",1);
       build(t);
   }
   void build(string &s)
   {
       int n=s.length();
       
       p.assign(n,0);
       
       int l=1;
       int r=1;
       
       for(int i=0;i<n;i++)
       {
            if((l+r)>=i)
            {
                p[i]=max(1,min(p[i],p[l+r-i]));
            }
            
            while((i+p[i])<n && (i-p[i])>=0 && s[i+p[i]]==s[i-p[i]])
            {
                p[i]++;
            }
            if(i+p[i]>r)
            {
                l=i-p[i];
                r=i+p[i];
            }
       }
   }
   
   int longest(int centre,int odd)
   {
       int pos=2*centre+1+!(odd==1);
       
       return p[pos];
   }
   bool isPalindrome(int l,int r)
   {
       int len=r-l+1;
       int center=(l+r)/2;
       int odd=((l%2)==(r%2));
       
       return (len<=longest(center,odd));
   }
   
   
   
};
void solve()
{
    int n;
    cin>>n;

    vector<vector<int>>arr(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>arr[i][j];
    }
    vector<Manacher>p;
        vector<Manacher>q;
        // int n=arr.size();
        for(int i=0;i<n;i++)
        {
            string s="";
            for(int j=0;j<n;j++)
            {
                s+=(arr[i][j]+'0');
            }
            Manacher m(s);
            p.push_back(m);
        }
        for(int j=0;j<n;j++)
        {
            string s="";
            for(int i=0;i<n;i++)
            {
                s+=(arr[i][j]+'0');
            }
            Manacher m(s);
            q.push_back(m);
        }
        
        int res=-1;
        int idx=0;
        char ch='/';
        for(auto &it:p)
        {
            if(it.isPalindrome(0,n-1))
            {
                res=idx;
                ch='R';
                debug(res);
                break;
            }
            idx++;
        }
        idx=0;
        for(auto &it:q)
        {
            if(it.isPalindrome(0,n-1) && res!=-1)
            {
                res=idx;
                ch='C';
                break;
            }
            idx++;
        }
        
        if(res==-1)
        cout<<to_string(res)<<endl;
        
        string s=to_string(res);
        // debug(s);
        s+=" ";
        s+=ch;
        cout<<s<<endl;
}