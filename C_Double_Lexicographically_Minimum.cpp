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
    string s;
    cin>>s;
    int n=s.length();
    sort(all(s));
    // reverse(all(s));
    string y1="";
    string y2="";
    string rem="";
    int flag=0;
    for(int i=0;i<n;i++)
    {
        rem+=s[i];
        if(rem.length()==2)
        {
            sort(all(rem));

            if(flag)
            {
                y1+=rem[0];
                y2=rem[1]+y2;
            }
            else
            {
                if(rem[0]!=rem[1])
                flag=1;
                y1+=rem[1];
                y2=rem[0]+y2;
            }
            rem="";
        }
    }
    string res=y1+rem+y2;
    int i=0;
    int j=res.length()-1;
    while(i+1<j)
    {
        if(res[i]>res[j]  && (res[j-1]==res[i]))
        {
            // cout<<i<<" "<<j<<endl;
            swap(res[j],res[j-1]);
        }
        i++;
        j--;
    }
    cout<<res<<endl;
}