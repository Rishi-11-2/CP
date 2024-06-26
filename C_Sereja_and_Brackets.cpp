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
struct Node{
    int closing;
    int opening;
    int val;
    Node()
    {
        closing =0;
        opening =0;
        val=0;
    }  
};
class SegmentTree{
    public:
    vector<Node>tree;
    int n;
    vector<int>arr;
    SegmentTree(int nn,vector<int>&v)
    {
        n=nn;
        tree.resize(4*n);
        arr=v;

        build(0,n-1,0);
    }
    Node merge(Node a,Node b)
    {
        int openingL=a.opening-(a.val)/2;
        int closingR=b.closing-(b.val)/2;

        Node c;
        c.opening = a.opening + b.opening;
        c.closing=a.closing+b.closing;

        c.val=a.val+b.val+min(openingL,closingR)*2;

        return c;
    }
    void build(int ss,int se,int si)
    {
        if(ss==se)
        {
            if(arr[ss]==1)
            tree[si].opening=1;
            else
            tree[si].closing=1;
            return ;
        }

        int mid=(ss+se)/2;

        build(ss,mid,2*si+1);
        build(mid+1,se,2*si+2);

        tree[si]=merge(tree[2*si+1],tree[2*si+2]);
    }

    Node query(int ss,int se,int si,int l,int r)
    {
        if(ss>r || se<l)
        {
            Node a;
            return a;
        }

        if(ss>=l && se<=r)
        {
            return tree[si];
        }

        int mid=(ss+se)/2;

        return merge(query(ss,mid,2*si+1,l,r),query(mid+1,se,2*si+2,l,r));
    }

    Node make_query(int l,int r)
    {
        return query(0,n-1,0,l,r);
    }

};
void solve()
{
    string s;
    cin>>s;

    vector<int>v;
    for(char c:s)
    {
        if(c=='(')
        {
            v.push_back(1);
        }
        else
        {
            v.push_back(-1);
        }
    }
    SegmentTree st(s.length(),v);
    int q;
    cin>>q;

    vector<int>res;
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        res.push_back(st.make_query(l-1,r-1).val);
    }

    for(auto it:res)
    cout<<it<<endl;
}