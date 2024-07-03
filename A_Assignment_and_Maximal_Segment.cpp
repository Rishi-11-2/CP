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
struct Node{
    long long segmentSum;
    long long pSum;
    long long suffixSum;
    long long mSum;
    Node()
    {
        segmentSum=0;
        suffixSum=0;
        pSum=0;
        mSum=0;
    }
    
};
class LazySegmentTree{
    public:
    vector<Node>tree;
    vector<long long>lazy;
    long long n;
    vector<long long>arr;
    long long xx;
    LazySegmentTree(vector<long long>&v)
    {
        arr=v;
        n=(long long)v.size();
        tree.resize(4*n);
        xx=-(long long)(1e10);
        lazy.assign(4*n,xx);
        build(0,n-1,0);
    }
    void push(long long ss,long long se,long long si)
    {
        if(lazy[si]==xx)
        return ;

        tree[si].segmentSum=(lazy[si])*(se-ss+1);
        tree[si].pSum=max(0LL,(lazy[si])*(se-ss+1));
        tree[si].suffixSum=max(0LL,(lazy[si])*(se-ss+1));
        tree[si].mSum=max(0LL,(lazy[si])*(se-ss+1));

        if(ss!=se)
        {
            lazy[2*si+1]=lazy[si];
            lazy[2*si+2]=lazy[si];
        }
        lazy[si]=xx;
    }
    Node combine(Node &a, Node &b)
    {
        Node c;
        c.segmentSum=a.segmentSum+b.segmentSum;

        c.pSum=max(a.pSum,a.segmentSum+b.pSum);

        c.suffixSum=max(b.suffixSum,b.segmentSum+a.suffixSum);

        c.mSum=max({a.mSum,b.mSum,a.suffixSum+b.pSum});
        return c;
    }
    void build(long long ss,long long se,long long si)
    {
        if(ss==se)
        {
            tree[si].segmentSum=arr[se];
            tree[si].pSum=max(0LL,arr[se]);
            tree[si].mSum=max(0LL,arr[se]);
            tree[si].suffixSum=max(0LL,arr[se]);
            return ;
        }

        long long mid=(ss+se)/2;

        build(ss,mid,2*si+1);
        build(mid+1,se,2*si+2);

        tree[si]=combine(tree[2*si+1],tree[2*si+2]);
    }
    void update(long long ss,long long se,long long si,long long l,long long r,long long val)
    {
        push(ss,se,si);

        if(ss>r || se<l)
        return ;

        if(ss>=l && se<=r)
        {
            lazy[si]=val;
            push(ss,se,si);
            return ;
        }

        long long mid=(ss+se)/2;

        update(ss,mid,2*si+1,l,r,val);

        update(mid+1,se,2*si+2,l,r,val);

        tree[si]=combine(tree[2*si+1],tree[2*si+2]);

    }

    Node query(long long ss,long long se,long long si,long long l,long long r)
    {
        push(ss,se,si);
        if(se<l || ss>r)
        {
            Node c;
            return c;
        }

        if(ss>=l && se<=r)
        return tree[si];
        
        long long mid=(ss+se)/2;
        auto  left=query(ss,mid,2*si+1,l,r);
        auto right=query(mid+1,se,2*si+2,l,r);
        return combine(left,right);
    }

    void make_update(long long l,long long r,long long val)
    {
        update(0,n-1,0,l,r,val);
    }

    Node make_query(long long l,long long r)
    {
        return query(0,n-1,0,l,r);
    }
};
void solve()
{

    long long n,q;
    cin>>n>>q;


   vector<long long>v(n,0);

   LazySegmentTree lsgt(v);


   for(long long i=1;i<=q;i++)
   {
     long long l,r,v;
     cin>>l>>r>>v;

      lsgt.make_update(l,r-1,v);
      cout<<lsgt.make_query(0,n-1).mSum<<endl;
   }



}