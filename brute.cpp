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
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int t=1;
    while (t--)
    {
        solve();
    }
}
class DisjointSet {
private:
    vector<int> par, count;
public:
    DisjointSet(int n) {
        par.resize(n+1);
        count.resize(n+1,1);
        for (int i=0; i<=n; i++) {
            par[i]=i;
        }
    }

    int findParent(int i) {
        if (par[i]!=i) {
            par[i]=findParent(par[i]); 
        }

        return par[i];
    }

    int unite(int A, int B) {
        A=findParent(A);
        B=findParent(B);
        if (A==B) return 0;
        if (count[A]==count[B]) {
            count[A]+=count[B];
            par[B]=A;
        } else if (count[A]<count[B]) {
            count[B]+=count[A];
            par[A]=B;
        } else {
            count[A]+=count[B];
            par[B]=A;
        }
        return 1;
    }

    int numbers(int n) {
        int ans=0;
        for (int i=0; i<=n; i++) {
            if (par[i]==i) {
                ans+=count[i]-1;
            }
        }
        return ans;
    }
};

void solve()
{
    int n;
    cin>>n;
    // cout<<n<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    map<int,int> m;
    int count=0;
    for (int i=0;i<n;i++) {
        if(m.find(v[i])==m.end()) m[v[i]]=count++;
    }
    for(int &i:v) i=m[i];
    DisjointSet ds(n);
    for(int i=0;i<n/2;i++) {
        if(v[i]!=v[n-i-1]) ds.unite(v[i],v[n-i-1]);
    }
    cout<<ds.numbers(n)<<endl;
}
