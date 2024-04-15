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
void solve()
{
    int l;
    cin>>l;

    int r;
    cin>>r;

    string ls=to_string(l);
    string rs=to_string(r);


    int n=rs.length();
    while(ls.length()<n)
    {
        ls=to_string(0)+ls;
    }

            int m=pow(10,n);
        // cout<<m<<endl;
        m--;
        string s=to_string(m);
        int len=s.length();
        // cout<<s<<endl;
        vector<vector<vector<int>>>dp(len+1,vector<vector<int>>(3,vector<int>(2049,-1)));
        function<int(int,int,int)>f=[&](int i,int tight,int mask)->int{

        if(i==len)
        {
            // if(mask==1)
            // {
            //     cout<<mask<<endl;
            // }
            // cout<<mask<<endl;
            return 1;
        }
        if(dp[i][tight][mask]!=-1)
        return dp[i][tight][mask];
        int low=0;
        int high=(tight==1)?(s[i]-'0'):9;
        // cout<<low<<" "<<high<<endl;
        int res=0;
        for(int j=low;j<=high;j++)
        {
            int newTight=0;
            if(tight==1)
            {
                if(j==high)
                newTight=1;
            }

            if(((mask&(1<<j))!=0))
            {
                // int y=f(i+1,newTight,mask);
                // res+=y;
                continue;
            }
            int newMask=mask|(1<<j);
            if(mask==0 && j==0)  // to account for the case like 000012 or the numbers
            // whose length is not equal to maximum length
            newMask=0;
            int x=f(i+1,newTight,newMask);
            res+=x;
        }

        return dp[i][tight][mask]=res;
     };

     int x=f(0,1,0);
     return x;
}