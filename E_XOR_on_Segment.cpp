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
// typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
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
    vector<int>b;
    long long value;
    Node()
    {
        b.assign(21,0);
        value=0;
    }
    Node(int a)
    {
        value=a;
        b.assign(21,0);
        for(int i=0;i<21;i++)
        {
            if(a&(1LL<<i))
            b[i]=1;
        }
    }
};
class LazySegmentTree{
    public:
    vector<Node>tree;
    vector<int>lazy;
    int n;
    vector<int>arr;
    LazySegmentTree(int nn,vector<int>&v)
    {
        arr=v;
        n=nn;
        tree.resize(4*n);
        lazy.assign(4*n,0);
        build(0,n-1,0);
    }
    Node combine(Node a,Node b)
    {
        Node c;
        c.value=a.value+b.value;
        for(int i=0;i<21;i++)
        {
            c.b[i]=(a.b[i]+b.b[i]);
        }
        return c;
    }
    void build(int ss,int se,int si)
    {
        if(ss==se)
        {
            Node a(arr[se]);
            tree[si]=a;
            return;
        }

        int mid=(ss+se)/2;
        build(ss,mid,2*si+1);
        build(mid+1,se,2*si+2);

        tree[si]=combine(tree[2*si+1],tree[2*si+2]);
    }
    Node combine1(Node a,int x,int len)
    {
        long long sum=0;
        Node c;
        for(int i=0;i<21;i++)
        {

            if(x&(1LL<<i))
            {
                sum+=(len-a.b[i])*(1LL<<i);
                c.b[i]=(len-a.b[i]);
            }
            else
            {
               c.b[i]=a.b[i];
                sum+=(a.b[i]*(1LL<<i));
            }
        }
        c.value=sum;

        return c;
    }
    void push(int ss,int se,int si)
    {
        if(lazy[si]==0)
        return;
        int len=(se-ss+1);
        tree[si]=combine1(tree[si],lazy[si],len);

        if(ss!=se)
        {
            lazy[2*si+1]^=lazy[si]; 
            lazy[2*si+2]^=lazy[si];
        }
        lazy[si]=0;
    }

    void update(int ss,int se,int si,int l,int r,int val)
    {
        push(ss,se,si);

        if(ss>r || se<l)
        return ;

       if(ss>=l && se<=r)
       {
           lazy[si]^=val;
           push(ss,se,si);
           return;
       }

       int mid=(ss+se)/2;

       update(ss,mid,2*si+1,l,r,val);
       update(mid+1,se,2*si+2,l,r,val);

       tree[si]=combine(tree[2*si+1],tree[2*si+2]);
    }


    Node query(int ss,int se,int si,int l,int r)
    {
        push(ss,se,si);
        

        if(ss>r || se<l)
        {
            Node c;
            return c;
        }
        
        if(ss>=l && se<=r)
        return tree[si];
       
        int mid=(ss+se)/2;

        return combine(query(ss,mid,2*si+1,l,r),query(mid+1,se,2*si+2,l,r));
    }


    void make_update(int l,int r,int val)
    {
        update(0,n-1,0,l,r,val);
    }

    Node make_query(int l,int r)
    {
        return query(0,n-1,0,l,r);
    }
};
void solve()
{
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    int m;
    cin>>m;
    LazySegmentTree lsgt(n,arr);
    for(int i=1;i<=m;i++)
    {
        int type;
        cin>>type;

        if(type==1)
        {
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            cout<<lsgt.make_query(l,r).value<<endl;

        }
        else
        {
            int l,r,x;
            cin>>l>>r>>x;
            l--;
            r--;
            lsgt.make_update(l,r,x);
        }
    }
}