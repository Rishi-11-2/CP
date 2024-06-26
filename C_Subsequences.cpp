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
class SegmentTree{
    public:
    vector<long long>tree;
    long long n;
    vector<long long>arr;
    SegmentTree(long long nn,vector<long long>&v)
    {
        n=nn;
        arr=v;
        tree.resize(4*n);

        build(0,n-1,0);
    }

    void build(long long ss,long long se,long long si)
    {
        if(ss==se)
        {
            tree[si]=arr[se];
            return ;
        }

        long long mid=(ss+se)/2;

        build(ss,mid,2*si+1);
        build(mid+1,se,2*si+2);

        tree[si]=tree[2*si+1]+tree[2*si+2];
    }


    void update(long long ss,long long se,long long si,long long pos,long long val)
    {
        if(ss==se)
        {
            tree[si]=val;
            return ;
        }

        long long mid=(ss+se)/2;

        if(pos<=mid)
        {
            update(ss,mid,2*si+1,pos,val);
        }
        else
        {
            update(mid+1,se,2*si+2,pos,val);
        }

        tree[si]=(tree[2*si+1]+tree[2*si+2]);
    }

    long long query(long long ss,long long se,long long si,long long l,long long r)
    {
        
        if(l>se || r<ss)
        return 0;
        
        if(ss>=l && se<=r)
        {
            return tree[si];
        }

        long long mid=(ss+se)/2;
        return query(ss,mid,2*si+1,l,r)+query(mid+1,se,2*si+2,l,r);
    }


    void make_update(long long pos,long long val)
    {
        update(0,n-1,0,pos,val);
    }

    long long make_query(long long l,long long r)
    {
        return query(0,n-1,0,l,r);
    }
    
};
void solve()
{
    long long n,k;
    cin>>n>>k;

    vector<long long>a(n);
    for(long long i=0;i<n;i++)
    cin>>a[i];
    vector<long long>v(n,0);
   vector<SegmentTree>dp(k+2,SegmentTree(n,v));
   for(long long i=0;i<n;i++)
   {
      dp[1].make_update(a[i]-1,1);
      for(long long j=2;j<=k+1;j++)
      {
        long long val=dp[j-1].make_query(0,a[i]-2);

        dp[j].make_update(a[i]-1,val);
      }
   }

   cout<<dp[k+1].make_query(0,n-1)<<endl;
    
}