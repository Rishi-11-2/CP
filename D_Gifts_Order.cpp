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
template<typename Node, typename Update>
struct SegTree {
	vector<Node> tree;
	vector<long long> arr; // type may change
	long long n;
	long long s;
	SegTree(long long a_len, vector<long long> &a) { // change if type updated
		arr = a;
		n = a_len;
		s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
		tree.resize(s); 
		build(0, n - 1, 1);
	}
	void build(long long start, long long end, long long index)  // Never change this
	{
		if (start == end)	{
			tree[index] = Node(arr[start],start);
			return;
		}
		long long mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(long long start, long long end, long long index, long long query_index, Update &u)  // Never Change this
	{
		if (start == end) {
			u.apply(tree[index]);
			return;
		}
		long long mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, u);
		else
			update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(long long start, long long end, long long index, long long left, long long right) { // Never change this
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		long long mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(long long index, long long val) {  // pass in as many parameters as required
		Update new_update = Update(val,index); // may change
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(long long left, long long right) {
		return query(0, n - 1, 1, left, right);
	}
};

struct Node1 {
	long long maxm; 
	long long minm; 
	long long res; 
    long long left;
    long long right;
	Node1() { 
		maxm=0;
        minm=(long long)(1e9); 
        res=0;
        left=-1;
        right=-1;
	}
	Node1(long long p1,long long i) {  // Actual Node
		maxm=p1;
        minm=p1;
        left=i+1;
        right=i+1;
        res=0;
	}
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		maxm=max(l.maxm,r.maxm);
        minm=min(l.minm,r.minm);
        left=l.left;
        right=r.right;
        res=max({l.res,r.res,(maxm-minm-(right-left))});
	}
};

struct Update1 {
	long long maxm; 
	long long minm; 
	long long res; 
    long long left;
    long long right;
	Update1(long long p1,long long i) { // Actual Update
		maxm=p1;
        minm=p1;
        res=0;
        left=i+1;
        right=i+1;
	}
	void apply(Node1 &a) { // apply update to given node
		a.maxm=maxm;
        a.minm=minm;
        a.res=res;
        a.left=left;
        a.right=right;
	}
};

void solve()
{

    long long n,q;
    cin>>n>>q;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    SegTree<Node1,Update1>s(n,arr);

    cout<<s.make_query(0,n-1).res<<endl;

    for(long long i=1;i<=q;i++)
    {
        long long idx,x;
        cin>>idx>>x;

        s.make_update(idx-1,x);
        cout<<s.make_query(0,n-1).res<<endl;


    }

}