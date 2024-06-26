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
    vector<long long>arr;
    long long n;
    SegmentTree(long long nn,vector<long long>&v)
    {
        n=nn;
        tree.resize(4*n);
        arr=v;
        build(0,n-1,0);
    }

    void build(long long ss,long long se,long long si)
    {
        if(ss==se)
        {
            tree[si]=arr[se];
            return;
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
            return;
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

        tree[si]=tree[2*si+1]+tree[2*si+2];
    }


    long long query(long long ss,long long se,long long si,long long l,long long r)
    {
        if(se<l || ss>r)
        {
            return 0;
        }

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
    long long n;
    cin>>n;

    long long arr[2*n];

    for(long long i=0;i<2*n;i++)
    cin>>arr[i];

    vector<long long>v(2*n,0);
    set<long long>s;

    for(long long i=0;i<2*n;i++)
    {
        if(s.find(arr[i])==s.end())
        {
            s.insert(arr[i]);
            v[i]=1;
        }
    }
    SegmentTree st(2*n,v);

    vector<long long>res(n+1,0);
    map<long long,long long>mp;
    for(long long i=0;i<2*n;i++)
    {
        if(mp.find(arr[i])==mp.end())
        {
            mp[arr[i]]=i;
        }
        else
        {
            st.make_update(mp[arr[i]],-1);
            st.make_update(i,1);
            res[arr[i]]=st.make_query(mp[arr[i]],i);
        }
    }
    for(long long i=1;i<=n;i++)
    cout<<res[i]<<" ";
    cout<<endl;
}