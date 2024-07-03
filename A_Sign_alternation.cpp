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
    vector<long long>arr;
    long long n;
    vector<long long>tree;
    SegmentTree(vector<long long>&v)
    {
        arr=v;
        n=(long long)v.size();
        tree.resize(4*n);
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
            arr[se]=val;
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
        return 0 ;
        
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
// can do with one segment tree also !!
void solve()
{
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<long long>v1(n);
    vector<long long>v2(n);
    for(long long i=0;i<n;i++)
    {
        if(i%2==0)
        {
            v1[i]=arr[i];
            v2[i]=-arr[i];
        }
        else
        {
            v1[i]=-arr[i];
            v2[i]=arr[i];
        }
    }

    SegmentTree even(v1);
    SegmentTree odd(v2);

    long long q;
    cin>>q;

    for(long long i=1;i<=q;i++)
    {
        long long type;
        cin>>type;
        if(type==0)
        {
            long long k,j;
            cin>>k>>j;
            k--;
            
            if(k%2==0)
            {
                even.make_update(k,j);
                odd.make_update(k,-j);
            }
            else
            {
                even.make_update(k,-j);
                odd.make_update(k,j);
            }
        }
        else
        {
            long long l,r;
            cin>>l>>r;
            r--;
            l--;
            if(l%2==0)
            {
                cout<<even.make_query(l,r)<<endl;
            }
            else
            {
                cout<<odd.make_query(l,r)<<endl;
            }
        }
    }
}