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
    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
class SegmentTree{
    public:
    long long n;
    vector<long long>arr;
    vector<long long>tree;

    SegmentTree(vector<long long>&a)
    {
        n=(long long)a.size();
        arr=a;
        tree.resize(4*n);

        build(0,n-1,0);
    }

    void build(long long ss,long long se,long long si)
    {
        if(ss==se)
        {
            tree[si]=arr[se];
            return ;
        }

        long long mid=(ss+se)/2;
        build(ss,mid,2*si+1);
        build(mid+1,se,2*si+2);

        tree[si]=__gcd(tree[2*si+1],tree[2*si+2]);
    }

    long long query(long long ss,long long se,long long si,long long l,long long r)
    {
        if(ss>r || se<l)
        return 0;

        if(ss>=l && se<=r)
        return tree[si];

        long long mid=(ss+se)/2;
       return __gcd(query(ss,mid,2*si+1,l,r),query(mid+1,se,2*si+2,l,r));
        
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

    vector<long long>arr(n);

    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<long long>v;

    for(long long i=0;i<(n-1);i++)
    {
        v.push_back(abs(arr[i]-arr[i+1]));
    }
    if((int)v.size()==0)
    {
        v.push_back(arr[0]);
    }
    SegmentTree sgt(v);

    for(long long i=1;i<=q;i++)
    {
        long long l,r;
        cin>>l>>r;
        if(l==r)
        {
            cout<<0<<" ";
            continue;
        }
        l-=1;
        r-=2;

        cout<<sgt.make_query(l,r)<<" ";
    }
    cout<<endl;
}