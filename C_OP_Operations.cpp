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
    long long t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
class LazySegmentTree{

    public:
    vector<long long>tree;
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
    
    void push(long long ss,long long se,long long si)
    {
        if(lazy[si]==0)
        return;
        tree[si]+=lazy[si]*(se-ss+1);
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
            tree[si]=arr[ss];
            return;
        }
        long long mid=(ss+se)/2;
        build(ss,mid,2*si+1);

        build(mid+1,se,2*si+2);

        tree[si]=tree[2*si+1]+tree[2*si+2];
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

        tree[si]=tree[2*si+1]+tree[2*si+2];
    }

    long long query(long long ss,long long se,long long si,long long l,long long r)
    {
        push(ss,se,si);
        if(ss>r || se<l)
        return 0;
        
        if(ss>=l && se<=r)
        {
            return tree[si];
        }

        long long mid=(ss+se)/2;
        return query(ss,mid,2*si+1,l,r)+query(mid+1,se,2*si+2,l,r);
    }
    void make_update(long long l,long long r,long long val)
    {
        update(0,n-1,0,l,r,val);
    }
    long long make_query(long long l,long long r)
    {
        return query(0,n-1,0,l,r);
    }
};
void solve()
{
    long long n,m,k;
    cin>>n>>m>>k;
    
    vector<long long>arr(n);
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    LazySegmentTree lsgt(n,arr);

    vector<long long>prefix(m,0);

    vector<vector<long long>>v(m,vector<long long>(3,0));
    for(long long i=0;i<m;i++)
    {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    for(long long i=0;i<k;i++)
    {
        long long x,y;
        cin>>x>>y;
        x--;
        y--;
        prefix[x]++;
        if(y+1<m)
        prefix[y+1]--;
    }
    for(long long i=1;i<m;i++)
    {
        prefix[i]+=prefix[i-1];
    }
    for(long long i=0;i<m;i++)
    {
        lsgt.make_update(v[i][0]-1,v[i][1]-1,prefix[i]*v[i][2]);
    }
    for(long long i=0;i<n;i++)
    {
        cout<<lsgt.make_query(i,i)<<" ";
    }
    cout<<endl;
}