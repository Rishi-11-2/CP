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
int countFreq(string& pat, string& txt)
{
    int M = pat.length();
    int N = txt.length();
    int res = 0;
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        /* For current index i, check for
           pattern match */
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
 
        // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        if (j == M) {
            res++;
        }
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

   string a="map";
   string b="pie";
   string c="mapie";
   int x=countFreq(a,s);
   int y=countFreq(b,s);
   int z=countFreq(c,s);
   cout<<(x+y-z)<<endl;
}