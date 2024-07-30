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
        tree[si]|=lazy[si];
        // debug(lazy[si],tree[si]);
        if(ss!=se)
        {
            lazy[2*si+1]|=lazy[si];
            lazy[2*si+2]|=lazy[si];
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

        tree[si]=(tree[2*si+1]|tree[2*si+2]);
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
            lazy[si]|=val;
            push(ss,se,si);
            return;
        }

        long long mid=(ss+se)/2;

        update(ss,mid,2*si+1,l,r,val);
        update(mid+1,se,2*si+2,l,r,val);

        tree[si]=(tree[2*si+1]|tree[2*si+2]);
    }

    long long query(long long ss,long long se,long long si,long long l,long long r)
    {
        push(ss,se,si);
        if(ss>r || se<l)
        return (1LL<<31)-1LL;
        
        if(ss>=l && se<=r)
        {
            return tree[si];
        }

        long long mid=(ss+se)/2;
        long long left=query(ss,mid,2*si+1,l,r);
        long long right=query(mid+1,se,2*si+2,l,r);
        long long yy=(left&right);
        return yy;
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
class LazySegmentTree1{

    public:
    vector<long long>tree;
    vector<long long>arr;
    long long n;
    LazySegmentTree1(long long nn,vector<long long>&a)
    {
        n=nn;
        tree.resize(4*n);
        arr=a;
        build(0,n-1,0);
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

        tree[si]=(tree[2*si+1]&tree[2*si+2]);
    }


    long long query(long long ss,long long se,long long si,long long l,long long r)
    {
        if(ss>r || se<l)
        return (1LL<<31)-1LL;
        
        if(ss>=l && se<=r)
        {
            return tree[si];
        }

        long long mid=(ss+se)/2;
        long long left=query(ss,mid,2*si+1,l,r);
        long long right=query(mid+1,se,2*si+2,l,r);
        long long yy=(left&right);
        return yy;
    }
    long long make_query(long long l,long long r)
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
    {
        v[i]=0;
    }

    LazySegmentTree lsgt(n,v);
    vector<pair<long long,long long>>vv;
    map<long long,long long>mp;
    for(long long i=1;i<=q;i++)
    {
        long long l,r,val;
        cin>>l>>r>>val;
        // debug()
        lsgt.make_update(l-1,r-1,val);
        vv.push_back({l-1,r-1});
        mp[i-1]=val;
    }
    vector<long long>arr;
    for(long long i=0;i<n;i++)
    {
        arr.push_back(lsgt.make_query(i,i));
    }
    
    LazySegmentTree1 lsgt2(n,arr);

    for(long long i=0;i<q;i++)
    {
        if(lsgt2.make_query(vv[i].first,vv[i].second)!=mp[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}