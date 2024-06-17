#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
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
       #ifndef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); 
       freopen("output.txt","w",stdout);
  #endif

       //Your Code

  #ifndef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); 
  #endif

            solve();
    
}
void solve()
{
            int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k = 0; // this is the second pointer
    vector<int> C(s + 1, -1); // Initialize C array with -1
    int ans = INT_MAX;

    // Iterate the array with the first pointer
    for (int i = 0; i < n; i++) {
        // Update C array
        for (int j = s; j >= a[i]; j--) {
            C[j] = max(C[j], C[j - a[i]]);
        }
        C[a[i]] = i;

        if (C[s] >= k) {
            ans = min(ans, i - C[s] + 1);
            k = C[s] + 1;
        }
    }

    cout << (ans < INT_MAX ? ans : -1) << endl;
}