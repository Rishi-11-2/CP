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

    sort(all(s));
    string left="";
    string right="";
    int n=s.length();
    if(n<=2)
    {
        reverse(all(s));
        cout<<s<<endl;
        return;
    }
    for(int i=0;i<n;i+=2)
    {
        if(i==n-1)
        {
            // left+=s[i];
            reverse(all(right));
            string ans=left+s[i]+right;
            cout<<ans<<endl;
            return;
        }
        // debug(i);
        if(s[i]==s[i+1])
        {
            left+=s[i];
            right+=s[i+1];
        }
        else{
            if((i+1)<n-1 && s[i+1]==s[n-1])
            {
                int cc=(n-1)-(i+1)+1;
                // debug(cc);
                int kk=cc/2;
                if(cc%2)
                kk++;
                for(int j=1;j<=kk;j++)
                {
                    left+=s[i+1];
                }
                kk=cc/2;
                for(int j=1;j<=kk;j++)
                {
                    right+=s[i+1];
                }
                // left+=s[i]

                reverse(all(right));
                // debug(left,right);
                string ans=left+s[i]+right;
                cout<<ans<<endl;
                return;
            }
            else
            {
                string x="";
                if(i+2<n)
                x=s.substr(i+2);
                reverse(all(right));
                // debug(x,left,right);
                string ans=left+s[i+1]+x+s[i]+right;
                cout<<ans<<endl;
                return ;
            }
        }
    }
    // debug(left,right);
    reverse(all(right));

    cout<<left+right<<endl;
}