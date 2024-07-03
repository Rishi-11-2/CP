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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
class SegmentTree{
    public:
    vector<int>tree;
    vector<int>arr;
    int n;
    SegmentTree(int nn,vector<int>&v)
    {
        arr=v;
        n=nn;
        tree.resize(4*n);
        build(0,n-1,0);
    }
    void build(int ss,int se,int si)
    {
        if(ss==se)
        {
            tree[si]=arr[se];
            return;
        }
        int mid=(ss+se)/2;
        build(ss,mid,2*si+1);
        build(mid+1,se,2*si+2);

        tree[si]=__gcd(tree[2*si+1],tree[2*si+2]);
    }

    int query(int ss,int se,int si,int l, int r)
    {
        if(se<l || ss>r)
        return 0;

        if(ss>=l && se<=r)
        return tree[si];

        int mid=(ss+se)/2;

        return __gcd(query(ss,mid,2*si+1,l,r),query(mid+1,se,2*si+2,l,r));
    }

    int make_query(int l,int r)
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
    {
        cin>>arr[i];
    }

    int low=0;
    int high=n;

    SegmentTree sgt(n,arr);
    function<int(int)>f=[&](int mid)->int{
        int i=0;
        set<int>s;
        while(i<n)
        {
            int low=i;
            int high=i+mid;
            if(high>=n)
            {
                s.insert(__gcd(sgt.make_query(low,n-1),sgt.make_query(0,mid-n+low)));
            }
            else
            s.insert(sgt.make_query(i,i+mid));
            i++;
        }

        if((int)s.size()==1)
        return 1;
        return 0;
    };
    int res=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(f(mid))
        {
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    cout<<res<<endl;
}