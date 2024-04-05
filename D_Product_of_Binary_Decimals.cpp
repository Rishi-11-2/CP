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
    int n;
    cin>>n;

    vector<int>v;
    function<void(int,string)>f=[&](int i, string s)->void{
        if(i==5)
        {
            int x=stoi(s);
            if(x>1)
            {
                // cout<<x<<endl;
                v.push_back(x);
            }
            return ;
        }
        s[i]='0';
        f(i+1,s);
        s[i]='1';
        f(i+1,s);
    };
    char c='0';
    string s;
    for(int i=0;i<5;i++)
    {
        s+=c;
    }
    f(0,s);
    int k=n;
    int flag=1;
    while(k>0)
    {
        int r=k%10;
        if(r>1)
        {
            flag=0;
        }
        k=k/10;
    }
    if(flag)
    {
        cout<<"YES"<<endl;
        return;
    }
    sort(all(v));
    // debug("Hi");
    for(auto it:v)
    {
        if(n<it)
        {
            break;
        }
        while(n%it==0)
        {
            // debug(it);
            n=n/it;
        }
    }
    if(n==1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

}