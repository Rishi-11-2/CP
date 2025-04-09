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
void solve()
{
    long long n;
    cin>>n;
    vector<vector<char>>grid(2,vector<char>(n+10,'/'));

    for(long long i=0;i<2;i++)
    {
        for(long long j=0;j<n;j++)
        cin>>grid[i][j];
    }

    vector<vector<long long>>dp(n+10,vector<long long>(7,0));


    /*

    4 Ls

    1 2d 3s (2 rows)

    2 slanted 3s


    7 types of shapes are there (4Ls , two rows stacked over one another, two rows with one inclined to the left and one to the right)
    
    */
    function<long long(long long,long long)>f=[&](long long i,long long k)->long long{
        long long counta=0;
        long long countj=0;
        if(k==0)
        {
            if(grid[0][i]=='A')
            counta++;
            else if(grid[0][i]=='J')
            countj++;

            if(grid[1][i]=='A')
            counta++;
            else if(grid[1][i]=='J')
            countj++;

            if(grid[1][i+1]=='A')
            counta++;
            else if(grid[1][i+1]=='J')
            countj++;
        }
        else if(k==1)
        {
            if(grid[0][i+1]=='A')
            counta++;
            else if(grid[0][i+1]=='J')
            countj++;

            if(grid[1][i+1]=='A')
            counta++;
            else if(grid[1][i+1]=='J')
            countj++;

            if(grid[1][i]=='A')
            counta++;
            else if(grid[1][i]=='J')
            countj++;
        }
        else if(k==2)
        {
            if(grid[0][i]=='A')
            counta++;
            else if(grid[0][i]=='J')
            countj++;

            if(grid[1][i]=='A')
            counta++;
            else if(grid[1][i]=='J')
            countj++;

            if(grid[0][i+1]=='A')
            counta++;
            else if(grid[0][i+1]=='J')
            countj++;
        }
        else if(k==3)
        {
            if(grid[0][i+1]=='A')
            counta++;
            else if(grid[0][i+1]=='J')
            countj++;

            if(grid[1][i+1]=='A')
            counta++;
            else if(grid[1][i+1]=='J')
            countj++;

            if(grid[0][i]=='A')
            counta++;
            else if(grid[0][i]=='J')
            countj++;
        }
        else if(k==4)
        {
            long long c1=0;
            long long c2=0;
            if(grid[0][i]=='A')
            c1++;
            if(grid[0][i+1]=='A')
            c1++;
            if(grid[0][i+2]=='A')
            c1++;

            if(grid[1][i]=='A')
            c2++;
            if(grid[1][i+1]=='A')
            c2++;
            if(grid[1][i+2]=='A')
            c2++;

            long long s=0;

            if(c1==2)
            s++;
            if(c2==2)
            s++;

            return s;

        }
        else if(k==5)
        {
            long long c1=0;
            long long c2=0;
            if(grid[0][i+1]=='A')
            c1++;
            if(grid[0][i+2]=='A')
            c1++;
            if(grid[0][i+3]=='A')
            c1++;

            if(grid[1][i]=='A')
            c2++;
            if(grid[1][i+1]=='A')
            c2++;
            if(grid[1][i+2]=='A')
            c2++;

            long long s=0;

            if(c1==2)
            s++;
            if(c2==2)
            s++;

            return s;
        }
        else
        {
            long long c1=0;
            long long c2=0;
            if(grid[0][i]=='A')
            c1++;
            if(grid[0][i+1]=='A')
            c1++;
            if(grid[0][i+2]=='A')
            c1++;

            if(grid[1][i+1]=='A')
            c2++;
            if(grid[1][i+2]=='A')
            c2++;
            if(grid[1][i+3]=='A')
            c2++;

            long long s=0;

            if(c1==2)
            s++;
            if(c2==2)
            s++;

            return s;

        }

        if(counta>countj)
        return 1;

        return 0;
    };
    for(long long k=n-1;k>=0;k--)
    {
        dp[k][0]=f(k,0)+max(dp[k+1][3],dp[k+1][6]);
        dp[k][1]=f(k,1)+max({dp[k+2][2],dp[k+2][0],dp[k+2][4]});
        dp[k][2]=f(k,2)+max(dp[k+1][1],dp[k+1][5]);
        dp[k][3]=f(k,3)+max({dp[k+2][0],dp[k+2][2],dp[k+2][4]});
        dp[k][4]=f(k,4)+max({dp[k+3][0],dp[k+3][2],dp[k+3][4]});
        dp[k][5]=f(k,5)+max(dp[k+3][1],dp[k+3][5]);
        dp[k][6]=f(k,6)+max(dp[k+3][3],dp[k+3][6]); 
    }

    cout<<max({dp[0][2],dp[0][0],dp[0][4]})<<endl;
}