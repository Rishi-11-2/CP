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
    long long prefix;
    long long suffix;
    long long ans;
    Node()
    {
        ans=0;
        prefix=0;
        suffix=0;
    }
    Node(long long a)
    {
        // debug(a);
        ans=0;
        prefix=a;
        suffix=a;
    }
};
class SegmentTree{
    public:
    vector<Node>tree;
    string s;
    long long n;
    SegmentTree(string &a)
    {
        n=a.length();
        s=a;
        tree.resize(4*n);
        build(0,n-1,0);
    }
    Node merge(Node &a,Node &b)
    {
        Node c;
        c.prefix=a.prefix;
        c.suffix=b.suffix;
        // debug(a.suffix,b.prefix);
        long long d=(a.suffix+b.prefix);
        if(d>1)
        {
            d=(d+1);
        }
        c.ans=d/2+a.ans+b.ans;
        return c;
    }
    void build(long long ss,long long se,long long si)
    {
        if(ss==se)
        {
            long long x=0;
            if(s[se]=='.')
            x=1;
            Node c(x);
            tree[si]=c;
            // debug(c.prefix,c.suffix);
            return;
        }
        long long mid=(ss+se)/2;
        build(ss,mid,2*si+1);
        build(mid+1,se,2*si+2);
        // debug(tree[2*si+1].prefix,tree[2*si+1].suffix)
        tree[si]=merge(tree[2*si+1],tree[2*si+2]);
    }
    void update(long long ss,long long se,long long si,char ch,long long pos)
    {
        if(ss==se)
        {
            s[se]=ch;
            long long x=0;
            if(s[se]=='.')
            x=1;
            // debug(se,s[se],x)
            Node c(x);
            tree[si]=c;
            return;
        }

        long long mid=(ss+se)/2;
        if(pos<=mid)
        {
            update(ss,mid,2*si+1,ch,pos);
        }
        else
        {
            update(mid+1,se,2*si+2,ch,pos);
        }
        tree[si]=merge(tree[2*si+1],tree[2*si+2]);
    }

    Node query(long long ss,long long se,long long si,long long l,long long r)
    {
        if(se<l || ss>r)
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

    void make_update(char ch,long long pos)
    {
        update(0,n-1,0,ch,pos);
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
    string s;
    cin>>s;
    SegmentTree sgt(s);
    vector<long long>res;
    // debug(sgt.make_query(0,n-1).ans);
    for(long long i=1;i<=q;i++)
    {
        long long pos;
        char ch;
        
        cin>>pos>>ch;
        pos--;
        sgt.make_update(ch,pos);
        res.push_back(sgt.make_query(0,n-1).ans);
    }
    for(auto it:res)
    cout<<it<<endl;
}