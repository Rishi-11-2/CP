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
    long long n;
    vector<long long>arr;
    LazySegmentTree(long long nn,vector<long long>&v)
    {
        arr=v;
        n=nn;
        tree.resize(4*n);
        lazy.assign(4*n,0);
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

        tree[si]=max(tree[2*si+1],tree[2*si+2]);
    }

    void push(long long ss,long long se,long long si)
    {
        if(lazy[si]==0)
        return ;

        tree[si]+=lazy[si];

        if(ss!=se)
        {
            lazy[2*si+1]+=lazy[si];
            lazy[2*si+2]+=lazy[si];
        }
        lazy[si]=0;
    }

    void update(long long ss,long long se,long long si,long long l,long long r,long long val)
    {
        push(ss,se,si);

        if(ss>r || se<l)
        return ;

       if(ss>=l && se<=r)
       {
           lazy[si]+=val;
           push(ss,se,si);
           return;
       }

       long long mid=(ss+se)/2;

       update(ss,mid,2*si+1,l,r,val);
       update(mid+1,se,2*si+2,l,r,val);

       tree[si]=max(tree[2*si+1],tree[2*si+2]);
    }


    long long query(long long ss,long long se,long long si,long long l,long long r)
    {
        push(ss,se,si);
        if(ss>r || se<l)
        {
            return INT_MIN;
        }
        if(ss>=l && se<=r)
       {
           return tree[si];
       }

        long long mid=(ss+se)/2;
        
        return max(query(ss,mid,2*si+1,l,r),query(mid+1,se,2*si+2,l,r));
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
    long long n,m;

    cin>>n>>m;

    vector<long long>v(n,0);
    LazySegmentTree lsgt(n,v);
    vector<long long>res;
    for(long long i=1;i<=m;i++)
    {
        long long type;
        cin>>type;
        if(type==1)
        {
            long long l,r,u;
            cin>>l>>r>>u;
            r--;
            lsgt.make_update(l,r,u);
        }
        else
        {
            long long l,k;
            cin>>k>>l;
            long long low=l;
            long long high=n-1;

            long long ans=-1;
            while(low<=high)
            {
                long long mid=(low+high)/2;

                long long count=lsgt.make_query(low,mid);

                if(count>=k)
                {
                    ans=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }

            res.push_back(ans);
        }
    }

    for(auto it:res)
    cout<<it<<endl;
}