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
        solve();
}
void solve()
{
    int n;
    cin>>n;
    int cx=(n+1)/2;
    int cy=(n+1)/2;
    vector<vector<int>>v(n,vector<int>(n,0));
    vector<vector<int>>a(n,vector<int>(n,'/'));
    int nums=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=(nums)+'0';
            nums++;
        }
    }
    int nn=n;
    int m=n;
int i, k = 0, l = 0;
 
    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
    nums=1;
    while (k < m && l < n) {
        /* Print the first row from
               the remaining rows */
        for (i = l; i < n; ++i) {
            // cout << a[k][i] << " ";
            v[k][i]=(nums);
            nums++;
        }
        k++;
 
        /* Print the last column
         from the remaining columns */
        for (i = k; i < m; ++i) {
            // cout << a[i][n - 1] << " ";
            v[i][n-1]=(nums);
            nums++;
        }
        n--;
 
        /* Print the last row from
                the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                // cout << a[m - 1][i] << " ";
                v[m-1][i]=(nums);
                nums++;
            }
            m--;
        }
 
        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                // cout << a[i][l] << " ";
                v[i][l]=(nums);
                nums++;
            }
            l++;
        }
    }
    // v[cx-1][cy-1]='T';
    for(int i=0;i<nn;i++)
    {
        for(int j=0;j<nn;j++)
        {
            if(v[i][j]==(nn*nn))
            {
                cout<<'T'<<" ";
            }
            else
            {
                cout<<v[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}