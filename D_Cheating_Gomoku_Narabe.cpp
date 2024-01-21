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
    int h,w,k;
    cin>>h>>w>>k;
    char grid[h][w];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        cin>>grid[i][j];
    }
    int res=INT_MAX;
    for(int i=0;i<h;i++)
    {
        int j=0;
        int z=0;
        int prefix=0;
        int count=0;
        while(j<w)
        {
            if(grid[i][j]=='o'||grid[i][j]=='.')
            {
                if(grid[i][j]=='.')
                count++;
                prefix++;
            }
            if(grid[i][j]=='x')
            {
                prefix=0;
                count=0;
                z=j+1;
                j++;
                continue;
            }
            while(z<=j && prefix>k)
            {
               if(grid[i][z]=='o'||grid[i][z]=='.')
                {
                    if(grid[i][z]=='.')
                    count--;
                    prefix--;
                }
                z++;
            }
            if(prefix>=k)
            res=min(res,count);
            j++;
        }
    }

    for(int j=0;j<w;j++)
    {
        int i=0;
        int z=0;
        int prefix=0;
        int count=0;
        while(i<h)
        {
            if(grid[i][j]=='o'||grid[i][j]=='.')
            {
                if(grid[i][j]=='.')
                count++;
                prefix++;
            }
            if(grid[i][j]=='x')
            {
                prefix=0;
                count=0;
                z=i+1;
                i++;
                continue;
            }
            while(z<=i && prefix>k)
            {
               if(grid[z][j]=='o'||grid[z][j]=='.')
                {
                    if(grid[z][j]=='.')
                    count--;
                    prefix--;
                }
                z++;
            }
            if(prefix>=k)
            res=min(res,count);
            i++;
        }
    }

    if(res==INT_MAX)
    cout<<-1<<endl;
    else
    cout<<res<<endl;

}