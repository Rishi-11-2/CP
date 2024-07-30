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
//(data type to be stored (pair,int ,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraint s)
typedef tree < int  , null_type,less<int >,rb_tree_tag,tree_order_statistics_node_update > pbds;
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
    vector<vector<int>>tree;
    vector<int >arr;
    int  n;
    SegmentTree(vector<int >&v)
    {
        n=(int )v.size();
        arr=v;
        int  s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
        tree.resize(s);
        build(0,n-1,0);
    }
    void build(int  ss,int  se,int  si)
    {
        if(ss==se)
        {
            tree[si].push_back(arr[se]);
            return ;
        }
        int  mid=(ss+se)/2;
        build(ss,mid,2*si+1);
        build(mid+1,se,2*si+2);
        merge(tree[2 * si+1].begin(), 
        tree[2 *si+1].end(),
        tree[2 *si + 2].begin(), 
        tree[2 *si + 2].end(),
        back_inserter(tree[si]));
        
    }

    int  query1(int  ss,int  se,int  si,int  l,int  r,int  x)
    {
        if(ss>r || se<l)
        return 0;
        
        if(ss>=l && se<=r)
        {
            int  ans=upper_bound(tree[si].begin(),tree[si].end(), x)-tree[si].begin();;
            int  sz=se-ss+1;
            ans=sz-ans;
            return ans;
        }

        int  mid=(ss+se)/2;
        return query1(ss,mid,2*si+1,l,r,x)+query1(mid+1,se,2*si+2,l,r,x);
    }
    int  query2(int  ss,int  se,int  si,int  l,int  r,int  x)
    {
        if(ss>r || se<l)
        return 0;
        
        if(ss>=l && se<=r)
        {
                int  ans=upper_bound(tree[si].begin(),tree[si].end(), x)-tree[si].begin();;            
                return ans;
        }

        int  mid=(ss+se)/2;
        return query2(ss,mid,2*si+1,l,r,x)+query2(mid+1,se,2*si+2,l,r,x);
    }
    int  make_query1(int  l,int  r,int  x)
    {
        return query1(0,n-1,0,l,r,x);
    }
    int  make_query2(int  l,int  r,int  x)
    {
        return query2(0,n-1,0,l,r,x);
    }

};
void solve()
{
    int  n;
    cin>>n;
    vector<int >v;
    for(int  i=1;i<=n;i++)
    {
        int  x;
        cin>>x;
        v.push_back(x);
    }
    SegmentTree sgt(v);
    long long  ans=0;
    for(int  i=1;i<n-1;i++)
    {
        long long  left=sgt.make_query1(0,i-1,v[i]);
        long long  right=sgt.make_query2(i+1,n-1,v[i]);
        ans+=(left*right);
    }
    cout<<ans<<endl;
}