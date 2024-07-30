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
class Node{
    public:
    long long sum;
    long long wsum;
    Node()
    {
        sum=0;
        wsum=0;
    }
    Node(long long a,long long idx)
    {
        sum=a;
        wsum=a*(idx+1);
    }
};
class LazySegmentTree{

    public:
    vector<Node>tree;
    vector<long long>lazy;
    vector<long long>arr;
    long long n;
    LazySegmentTree(long long nn,vector<long long>&a)
    {
        n=nn;
        tree.resize(4*n);
        lazy.resize(4*n);
        lazy.assign(4*n,0);
        arr=a;
        build(0,n-1,0);
    }
    Node merge(Node &a,Node &b)
    {
        Node c;
        c.sum=a.sum+b.sum;
        c.wsum=a.wsum+b.wsum;
        return c;
    }
    long long sum(long long l,long long r)
    {
        long long ans1=(r*(r+1))/2;
        long long ans2=(l*(l-1))/2;
        return ans1-ans2;
    }
    void push(long long ss,long long se,long long si)
    {
        if(lazy[si]==0)
        return;
        tree[si].sum+=lazy[si]*(se-ss+1);
        tree[si].wsum+=lazy[si]*sum(ss+1,se+1);
        if(ss!=se)
        {
            lazy[2*si+1]+=lazy[si];
            lazy[2*si+2]+=lazy[si];
        }
        lazy[si]=0;
    }

    void build(long long ss,long long se,long long si)
    {
        if(ss==se)
        {
            Node c(arr[ss],ss);
            tree[si]=c;
            return;
        }
        long long mid=(ss+se)/2;
        build(ss,mid,2*si+1);

        build(mid+1,se,2*si+2);

        tree[si]=merge(tree[2*si+1],tree[2*si+2]);
    }

    void update(long long ss,long long se,long long si,long long l,long long r,long long val)
    {
        push(ss,se,si);

        if(se<l || ss>r)
        {
            return;
        }

        if(ss>=l && se<=r)
        {
            lazy[si]=val;
            push(ss,se,si);
            return;
        }

        long long mid=(ss+se)/2;

        update(ss,mid,2*si+1,l,r,val);
        update(mid+1,se,2*si+2,l,r,val);

        tree[si]=merge(tree[2*si+1],tree[2*si+2]);
    }

    Node query(long long ss,long long se,long long si,long long l,long long r)
    {
        push(ss,se,si);
        if(ss>r || se<l)
        {
            Node c;
            return c;
        }
        
        if(ss>=l && se<=r)
        {
            return tree[si];
        }

        long long mid=(ss+se)/2;
        Node a=query(ss,mid,2*si+1,l,r);
        Node b=query(mid+1,se,2*si+2,l,r);
        return merge(a,b);
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

    vector<long long>v(n);
    for(long long i=0;i<n;i++)
    cin>>v[i];
    
    LazySegmentTree lsgt(n,v);

    for(long long i=1;i<=q;i++)
    {
        long long type;
        cin>>type;
        if(type==1)
        {
            long long l,r,d;
            cin>>l>>r>>d;
            lsgt.make_update(l-1,r-1,d);
        }
        else
        {
            long long l,r;
            cin>>l>>r;
            l--;r--;
            Node c=lsgt.make_query(l,r);
            long long val=c.wsum-max(0LL,(l))*c.sum;
            cout<<val<<endl;
        }
    }
}